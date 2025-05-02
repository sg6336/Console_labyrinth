#include "Server.h"

#include "Arduino.h"

#include <windows.h>
#include <conio.h>
#include <iostream>

constexpr int rows = 5;
constexpr int cols = 4;

int Server::x = 0;
int Server::y = 0;

namespace
{
    void updateCursor()
    {
        COORD coord = { (SHORT)Server::x, (SHORT)Server::y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
}

void Server::drawPlayer()
{
    updateCursor();
    std::cout << 'o';
}

void Server::processMove(bool canMove, char dir)
{
    if (!canMove)
        return;

    if (dir == 'a')
    {
        if (x > 0) { x -= 1; }
    }
    if (dir == 'd')
    {
        if (x < cols) { x += 1; }
    }
    if (dir == 'w')
    {
        if (y > 0) { y -= 1; }
    }
    if (dir == 's')
    {
        if (y < rows) { y += 1; }
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

    bool move = Arduino::move(ch);

    processMove(move, ch); // костиль переписать під івент

    drawPlayer();
}

bool Server::checkMove(char dir)
{
    if (dir == 'a')
    {
        if (x <= 0) { return false; }
    }
    if (dir == 'd')
    {
        if (x >= cols) { return false; }
    }
    if (dir == 'w')
    {
        if (y <= 0) { return false; }
    }
    if (dir == 's')
    {
        if (y >= rows) { return false; }
    }

    return true;
}