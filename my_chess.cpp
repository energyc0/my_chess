#include "chessBoard.h"
#include <iostream>

using namespace std;

int main()
{
	team Player = WHITE;	// ход белого
	chessBoard::startGame();	// начало игры
	while (true)
	{
		chessBoard::drawBoard(Player);	// прорисовать шахматную доску
		if (Player == WHITE)
			cout << "White";
		else
			cout << "Black";
		cout << " player`s turn				Commands:\n						'exit' for exit or enter coordinates of figure to move(example: A8, english letters)";

		chessBoard::moveFigure(&Player);	// двинуть фигуру
	}
}