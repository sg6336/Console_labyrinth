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
	static void drawMap();

	static void loadMap(const char* filepath);

	static void processInput();
	static void processMove(bool move, char dir);

	static bool checkMove(char key);
	static bool isWall(int x, int y);

	static constexpr int rows = 11;
	static constexpr int cols = 11;

	static int x;
	static int y;

	static int map[rows][cols];
};