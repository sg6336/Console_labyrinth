#include "Server.h"

#include "Arduino.h"

#include <windows.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>

constexpr int rows = 5;
constexpr int cols = 4;

int Server::x = 0;
int Server::y = 0;

int Server::map[rows][cols] = {};
namespace
{
    void updateCursor(int x, int y)
    {
        COORD coord = { (SHORT)x, (SHORT)y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
}

bool Server::isWall(int x, int y)
{
    return map[y][x] == '#';
}

void Server::loadMap(const char* filepath)
{
    std::ifstream file(filepath);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filepath << std::endl;
        return;
    }

    std::string line;

    for (size_t i = 0; i < rows; ++i)
    {
        if (std::getline(file, line))
        {
            // Fill each column in the row
            for (size_t j = 0; j < cols; ++j)
            {
                if (j < line.length())
                {
                    if (line[j] == 'S')
                    {
                        x = j;
                        y = i;
                    }

                    map[i][j] = line[j];
                }
                else
                {
                    map[i][j] = ' ';
                }
            }
        }
    }

    file.close();
}

void Server::drawPlayer()
{
    updateCursor(x, y);
    std::cout << 'o';
}

void Server::drawMap()
{
    for (size_t i = 0; i < rows; ++i)
    {
        updateCursor(0, static_cast<int>(i));
        for (size_t j = 0; j < cols; ++j)
        {
            updateCursor(static_cast<int>(j), static_cast<int>(i));

            std::cout << (char)map[i][j];
        }
    }
}

void Server::processMove(bool canMove, char dir)
{
    if (!canMove)
        return;

    if (dir == 'a')
    {
        if (x > 0 && map[y][x-1] != '#') { x -= 1; }
    }
    if (dir == 'd')
    {
        if (x < cols && map[y][x + 1] != '#') { x += 1; }
    }
    if (dir == 'w')
    {
        if (y > 0 && map[y - 1][x] != '#') { y -= 1; }
    }
    if (dir == 's')
    {
        if (y < rows && map[y + 1][x] != '#') { y += 1; }
    }
}

void Server::processInput()
{
    char ch = ' ';

    if (_kbhit())
    {
        ch = _getch();

        if (ch == 'w') { /*y--;*/ }
        if (ch == 's') { /*y++;*/ }
        if (ch == 'a') { /*x--;*/ }
        if (ch == 'd') { /*x++;*/ }
    }

    bool move = Arduino::askServerMove(ch);

    processMove(move, ch); // костиль переписать під івент

    drawPlayer();
}

bool Server::checkMove(char dir)
{
    if (dir == 'a') 
    { 
        if (x - 1 < 0 || isWall(x - 1, y)) { return false; }
    }
    if (dir == 'd')
    {
        if (x + 1 > cols || isWall(x + 1, y)) { return false; }
    }
    if (dir == 'w') 
    { 
        if (y - 1 < 0 || isWall(x, y - 1)) { return false; }
    }
    if (dir == 's')
    {
        if (y + 1 > rows || isWall(x, y + 1)) { return false; }
    }

    return true;
}