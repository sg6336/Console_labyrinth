#pragma once

class Arduino
{
public:
	static bool move(char key);
	static char move();
	static char makeDesicion(int i, char pdir);

	static int ax;
	static int ay;

	static int pax;
	static int pay;

	static char dir;

	static char pdir;

	static constexpr int rows = 10;
	static constexpr int cols = 10;

	static int visitCounts[rows + 1][cols + 1];
};