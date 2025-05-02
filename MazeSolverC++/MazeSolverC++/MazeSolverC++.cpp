#include <iostream>

#include "Server.h"
#include "Arduino.h"

#include <conio.h>     // Для _kbhit() і _getch()
#include <windows.h>
#include <iostream>

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

    while(1)
    {
        Server::processInput();
    }

    return 0;
}
