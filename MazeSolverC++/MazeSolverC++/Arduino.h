#pragma once

class Arduino
{
public:
	static bool askServerMove(char key);
	static char move();
	static char makeDesicion(int i, char pdir);

	static char getInverseDir(char dir);

	static int ax;
	static int ay;

	static int pax;
	static int pay;

	static const char dirs[4];

	static int dirIndex;

	static int pdirIndex;

	static constexpr int rows = 10;
	static constexpr int cols = 5;

	static int visitCounts[rows][cols];
};