#include <iostream>

#include "Server.h"
#include "Arduino.h"

#include <conio.h>     // Для _kbhit() і _getch()
#include <windows.h>
#include <iostream>

#include <cstdlib>

void MoveCursorTo(int x, int y) 
{
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    Server::loadMap("maze1.txt");
    Server::drawMap();
    Server::drawPlayer();

    while(1)
    {
        //Server::processInput();
        char dir = Arduino::move();
        //bool canMove = Arduino::askServerMove(dir);

        Server::processMove(true, dir); // костиль переписать під івент
       
        Server::drawPlayer();
    }

    return 0;
}
