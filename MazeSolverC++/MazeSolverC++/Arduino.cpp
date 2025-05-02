#include "Arduino.h"

#include "Server.h"

int Arduino::ax = 5;
int Arduino::ay = 5;

bool Arduino::move(char key)
{
    if (Server::checkMove(key))
        return true;

    return false;
}

char Arduino::move()
{
    while (1)
    {
        dir = makeDesicion();

        if (Server::checkMove(dir)) 
        { 
            ++visitCounts[ay][ax];
            break; 
        }
        else
        {
            visitCounts[ay][ax] = 255;
        }

        ax = pax;
        ay = pay;
    }

    return dir;
}

char Arduino::makeDesicion()
{
    if (dir == UP) { ay--; }
    if (dir == DOWN) { ay++; }
    if (dir == LEFT) { ax--; }
    if (dir == RIGHT) { ax++; }

    return LEFT;
}