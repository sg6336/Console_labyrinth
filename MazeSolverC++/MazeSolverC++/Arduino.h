#pragma once

class Arduino
{
public:
	static bool move(char key);
	static char move();
	static void makeDesicion();

	static int ax;
	static int ay;

	static int pax;
	static int pay;

	static char dir;

	static int visitCounts[11][11];
};

