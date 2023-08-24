#include "chessBoard.h"
#include <iostream>

using namespace std;

chess_figure* chessBoard::field[8][8];

void chessBoard::startGame()	// начало игры и расстановка фигур по местам
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (j == 0 || j == 7)
			{
				if (i == 0 || i == 7)
				{
					field[i][j] = new rook;
				}
				else if (i == 1 || i == 6)
				{
					field[i][j] = new knight;
				}
				else if (i == 2 || i == 5)
				{
					field[i][j] = new bishop;
				}
				else if (i == 3)
				{
					if (j == 0)
					{
						field[i][j] = new queen;
					}
					else
					{
						field[i][j] = new king;
					}
				}
				else
				{
					if (j == 0)
					{
						field[i][j] = new king;
					}
					else
					{
						field[i][j] = new queen;
					}
				}
			}
			else if (j == 1 || j == 6)
			{
				field[i][j] = new pawn;
			}
			else
			{
				field[i][j] = new cell(i,j);
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
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					chessBoard::drawWhiteCell(field[i][j]->returnEmblem());
				}
				else
				{
					chessBoard::drawBlackCell(field[i][j]->returnEmblem());
				}
			}
			else
			{
				if (j % 2 == 0)
				{
					chessBoard::drawBlackCell(field[i][j]->returnEmblem());
				}
				else
				{

					chessBoard::drawWhiteCell(field[i][j]->returnEmblem());
				}
			}
			if (i == 7)
			{
				cout << " | " << char(65 + j);	// указатель координат A - H
			}
		}
		cout << endl;
	}
	for (int i = 0; i < 26; i++)	// отделитель от координат
		cout << "-";
	cout << "\n 1  2  3  4  5  6  7  8 ";	// указатель координат 1 - 8;
}