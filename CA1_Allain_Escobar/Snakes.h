#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;


bool endGames;
const int mapWidth = 20;
const int mapHeight = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum Controls { STOP = 0, LEFT, RIGHT, UP, DOWN };
Controls dir;

void Setup()
{
	endGames = false;
	dir = STOP;
	x = mapWidth / 2;
	y = mapHeight / 2;
	fruitX = rand() % mapWidth;
	fruitY = rand() % mapHeight;
	score = 0;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < mapWidth + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}


			if (j == mapWidth - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < mapWidth + 2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << score << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			endGames = true;
			break;
		default:
			break;
		}
	}
}

void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > mapWidth || x < 0 || y > mapHeight || y < 0)
		endGames = true;

	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			endGames = true;

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % mapWidth;
		fruitY = rand() % mapHeight;
		nTail++;
	}
}

void snakes()
{
	Setup();
	while (!endGames)
	{
		Draw();
		Input();
		Logic();
		Sleep(50);
	}
}