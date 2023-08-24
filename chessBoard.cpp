#include "chessBoard.h"
#include <iostream>

using namespace std;

chessBoardElement* chessBoard::field[8][8];

void chessBoard::startGame()	// начало игры и расстановка фигур по местам
{
	team temp; // переменная определяющая команду фигуры
	for (int y = 0; y < 8; y++)
	{
		if (y == 0 || y == 1)
			temp = BLACK;
		else
			temp = WHITE;
		for (int x = 0; x < 8; x++)
		{
			if (y == 0 || y == 7)
			{
				if (x == 0 || x == 7)
				{
					field[x][y] = new rook(x,y, temp);
				}
				else if (x == 1 || x == 6)
				{
					field[x][y] = new knight(x, y, temp);
				}
				else if (x == 2 || x == 5)
				{
					field[x][y] = new bishop(x, y, temp);
				}
				else if (x == 3)
				{
					if (y == 0)
					{
						field[x][y] = new queen(x, y, temp);
					}
					else
					{
						field[x][y] = new king(x, y, temp);
					}
				}
				else
				{
					if (y == 0)
					{
						field[x][y] = new king(x, y, temp);
					}
					else
					{
						field[x][y] = new queen(x, y, temp);
					}
				}
			}
			else if (y == 1 || y == 6)
			{
				field[x][y] = new pawn(x, y, temp);
			}
			else
			{
				field[x][y] = new cell(x, y);
			}
		}
	}
}

void chessBoard::drawWhiteCell(char emb)	// нарисовать белую клетку с фигурой или без
{
	cout << char(219) << emb << char(219);
}

void chessBoard::drawBlackCell(char emb)	// нарисовать чёрную клетку с фигурой или без
{
	cout << char(177) << emb << char(177);
}

void chessBoard::drawBoard()	// консольная графика шахматной доски
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (x % 2 == 0)
			{
				if (y % 2 == 0)
				{
					chessBoard::drawWhiteCell(field[x][y]->returnEmblem());
				}
				else
				{
					chessBoard::drawBlackCell(field[x][y]->returnEmblem());
				}
			}
			else
			{
				if (y % 2 == 0)
				{
					chessBoard::drawBlackCell(field[x][y]->returnEmblem());
				}
				else
				{

					chessBoard::drawWhiteCell(field[x][y]->returnEmblem());
				}
			}
			if (x == 7)
			{
				cout << " | " << char(65 + y);	// указатель координат A - H
			}
		}
		cout << endl;
	}
	for (int i = 0; i < 26; i++)	// отделитель от координат
		cout << "-";
	cout << "\n 1  2  3  4  5  6  7  8 ";	// указатель координат 1 - 8;
}