using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;

namespace Console_labyrinth
{
    public static class labyrinth
    {
        static string pathFile = "C:\\Users\\Denys\\Downloads\\";
        static string nameFile = "ASCII-Maze.txt";


        static char[,] maze;
        static bool[,] visited;
        static int rows, cols;
        static List<string> path = new List<string>();

        // Направления: вверх, вниз, влево, вправо
        static int[] dRow = { -1, 1, 0, 0 };
        static int[] dCol = { 0, 0, -1, 1 };
        static char[] directions = { 'U', 'D', 'L', 'R' };  // Up, Down, Left, Right

        static public void Ran()
        {
            // Чтение лабиринта из файла
            string[] lines = File.ReadAllLines(pathFile + nameFile);
            rows = lines.Length;
            cols = lines[0].Length;

            maze = new char[rows, cols];
            visited = new bool[rows, cols];

            for (int i = 0; i < rows; i++) // TODO: окрема функція Check()
            {
                if (lines[i].Length != cols)
                {
                    Console.WriteLine("Ошибка: строки разной длины.");
                    return;
                }

                for (int j = 0; j < cols; j++)
                {
                    maze[i, j] = lines[i][j];
                }
            }

            // Печать лабиринта
            Console.WriteLine("Исходный лабиринт:");
            PrintMaze();

            // Запуск поиска пути с использованием DFS
            DFS_NonRecursive();

            // Печать найденного пути
            if (path.Count > 0) // TODO: 
            {
                Console.WriteLine("Путь к выходу:");
                foreach (var move in path)
                {
                    Console.Write(move + " ");
                }
                Console.WriteLine();
            }
            else
            {
                Console.WriteLine("Выход не найден");
            }

            // Печать лабиринта после того как робот прошел путь
            Console.WriteLine("\nЛабиринт после прохождения роботом:");
            PrintMaze();
        }

        static void DFS_NonRecursive()
        {
            Stack<(int row, int col, string direction)> stack = new Stack<(int, int, string)>();

            // Найдём стартовую точку
            int startRow = -1, startCol = -1;
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    if (maze[i, j] == 'S')
                    {
                        startRow = i;
                        startCol = j;
                    }

            if (startRow == -1)
            {
                Console.WriteLine("Стартовая точка 'S' не найдена.");
                return;
            }

            stack.Push((startRow, startCol, ""));
            visited[startRow, startCol] = true;

            while (stack.Count > 0)
            {
                var (r, c, direction) = stack.Pop();

                // Отмечаем путь, где был робот
                if (maze[r, c] != 'S' && maze[r, c] != 'E')
                {
                    maze[r, c] = 'o';  // Отметка посещенного места
                }

                if (maze[r, c] == 'E')
                {
                    // Если нашли выход, сохраняем путь
                    path.Add(direction);
                    Console.WriteLine($"Выход найден в ({r}, {c})");
                    return;
                }

                ////////////////////////////////////////////
                /// TODO: це має робити дві різні програми
                for (int i = 0; i < 4; i++)
                {
                    int newR = r + dRow[i];
                    int newC = c + dCol[i];
                    if (IsValid(newR, newC))
                    {
                        visited[newR, newC] = true;
                        string newDirection = direction + directions[i];
                        stack.Push((newR, newC, newDirection));
                    }
                }
                /////////////////////////////////////////////
            }

            Console.WriteLine("Выход не найден");
        }

        static bool IsValid(int r, int c)
        {
            return r >= 0 && r < rows &&
                   c >= 0 && c < cols &&
                   !visited[r, c] &&
                   maze[r, c] != '#';
        }

        // Печать лабиринта
        static void PrintMaze()
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    Console.Write(maze[i, j]);
                }
                Console.WriteLine();
            }
        }
    }

}
