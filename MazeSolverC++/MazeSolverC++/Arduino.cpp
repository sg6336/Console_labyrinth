#include "Arduino.h"

#include "Server.h"

int Arduino::ax = 5;
int Arduino::ay = 5;

int Arduino::pax = Arduino::ax;
int Arduino::pay = Arduino::ay;

int Arduino::dirIndex = 3;
int Arduino::pdirIndex = 3;

const char Arduino::dirs[4] = {'w', 's', 'a', 'd'};

int Arduino::visitCounts[rows][cols] = {};

char Arduino::getInverseDir(char dir)
{
    if (dir == UP) { return DOWN; }
    if (dir == DOWN) { return UP; }
    if (dir == LEFT) { return RIGHT; }
    if (dir == RIGHT) { return LEFT; }
}

bool Arduino::askServerMove(char key)
{
    if (Server::checkMove(key))
    {
        return true;
    }

    return false;
}

char Arduino::move()
{
    pax = ax;
    pay = ay;

    //dir = makeDesicion(i, pdir);
    dirIndex = pdirIndex;
    char dir = dirs[dirIndex];
    //if (dir == ' ') { continue; }

    if (askServerMove(dir))
    {
        ++visitCounts[ay][ax];

        return dir;
    }
    else
    {
        visitCounts[ay][ax] = 255;
    }

    /*ax = pax;
    ay = pay;*/

    for (int i = 1; i < 4; ++i)
    {
        dirIndex = (dirIndex + i) % 4;

        dir = makeDesicion(dirIndex, dirs[dirIndex]);

        if (dir == getInverseDir(dirs[pdirIndex])) { continue; }

        if (askServerMove(dir))
        {
            ++visitCounts[ay][ax];

            break;
        }
        else
        {
            visitCounts[ay][ax] = 255;
        }
    }

    if (dir == dirs[pdirIndex])
    {
        dir = getInverseDir(dir);
    }

    pdirIndex = dirIndex;

    ax = pax;
    ay = pay;

    return dir;
}

char Arduino::makeDesicion(int i, char pdir)
{
    //if (dir == UP) { ay--; }
    //if (dir == DOWN) { ay++; }
    //if (dir == LEFT) { ax--; }
    //if (dir == RIGHT) { ax++; }

    char result = ' ';

    if (i == 0) { result = UP; }
    if (i == 1) { result = DOWN; }
    if (i == 2) { result = LEFT; }
    if (i == 3) { result = RIGHT; }

    return result;
}