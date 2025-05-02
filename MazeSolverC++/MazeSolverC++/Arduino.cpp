#include "Arduino.h"

#include "Server.h"

int Arduino::ax = 5;
int Arduino::ay = 5;

int Arduino::pax = Arduino::ax;
int Arduino::pay = Arduino::ay;

char Arduino::dir = 'd';
char Arduino::pdir = 'd';

int Arduino::visitCounts[rows + 1][cols + 1] = {};

bool Arduino::move(char key)
{
    if (Server::checkMove(key))
    {
        return true;
    }

    return false;
}

char Arduino::move()
{
    //while (1)
    {
        pax = ax;
        pay = ay;

        //dir = makeDesicion(i, pdir);
        dir = pdir;
        //if (dir == ' ') { continue; }

        if (move(dir))
        {
            ++visitCounts[ay][ax];

            pdir = dir;

            return dir;
        }
        else
        {
            visitCounts[ay][ax] = 255;
        }

        /*ax = pax;
        ay = pay;*/

        for (int i = 0; i < 4; ++i)
        {
            dir = makeDesicion(i, pdir);

            if (dir == ' ') { continue; }

            if (move(dir))
            {
                ++visitCounts[ay][ax];

                pdir = dir;

                break;
            }
            else
            {
                visitCounts[ay][ax] = 255;
            }

            ax = pax;
            ay = pay;
        }
    }

    return dir;
}

char Arduino::makeDesicion(int i, char pdir)
{
    //if (dir == UP) { ay--; }
    //if (dir == DOWN) { ay++; }
    //if (dir == LEFT) { ax--; }
    //if (dir == RIGHT) { ax++; }

    char result;
    char ipdir;

    if (pdir == UP) { ipdir = DOWN; }
    if (pdir == DOWN) { ipdir = UP; }
    if (pdir == LEFT) { ipdir = RIGHT; }
    if (pdir == RIGHT) { ipdir = LEFT; }

    if (i == 0) { result = UP; }
    if (i == 1) { result = DOWN; }
    if (i == 2) { result = LEFT; }
    if (i == 3) { result = RIGHT; }

    if (result == ipdir) { result = ' '; }

    return result;
}