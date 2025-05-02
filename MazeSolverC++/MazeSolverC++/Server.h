#pragma once

enum Dir
{
	LEFT = 'a',
	RIGHT = 'd',
	UP = 'w',
	DOWN = 's'
};

class Server
{
public:
	static void drawPlayer();

	static void processInput();
	static void processMove(bool move, char dir);

	static bool checkMove(char key);

	static constexpr int rows = 11;
	static constexpr int cols = 11;

	static int x;
	static int y;


};