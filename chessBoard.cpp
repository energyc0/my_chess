#include "chessBoard.h"
#include <iostream>

using namespace std;

chess_figure* chessBoard::field[8][8];

void chessBoard::startGame()
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
				field[i][j] = new cell;
			}
		}
	}
}

void chessBoard::drawWhiteCell()
{
	cout << char(219) << char(219) << char(219);
}

void chessBoard::drawBlackCell()
{
	cout << char(177) << char(177) << char(177);
}

void chessBoard::drawBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (field[i][j]->returnEmblem() == 0) // если пустая клетка
			{
				if (i % 2 == 0)
				{
					if (j % 2 == 0)
					{
						chessBoard::drawWhiteCell();
					}
					else
					{
						chessBoard::drawBlackCell();
					}
				}
				else
				{
					if (j % 2 == 0)
					{
						chessBoard::drawBlackCell();
					}
					else
					{
						chessBoard::drawWhiteCell();
					}
				}
			}
			else
			{
				field[i][j]->showFigure();
			}
		}
		cout << endl;
	}
}





/*
switch (field[i][j]->returnEmblem())
{
	case char(239):	//пешка
	case char(232):	//королева
	case char(233):	//король
	case char(173): //слон
	case char(244): //конь
	case char(206): //ладья
}
*/
