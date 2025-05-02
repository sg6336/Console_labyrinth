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

    if (dir == LEFT)
    {
        if (x > 0) { x -= 1; }
    }
    if (dir == RIGHT)
    {
        if (x < cols) { x += 1; }
    }
    if (dir == UP)
    {
        if (y > 0) { y -= 1; }
    }
    if (dir == DOWN)
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

bool Server::checkMove(char key)
{
    return true;
}
