#include "chessBoard.h"
#include <iostream>

using namespace std;

int main()
{
	team Player = WHITE;	// ��� ������
	chessBoard::startGame();	// ������ ����
	while (true)
	{
		chessBoard::drawBoard(Player);	// ����������� ��������� �����
		if (Player == WHITE)
			cout << "White";
		else
			cout << "Black";
		cout << " player`s turn				Commands:\n						'exit' for exit or enter coordinates of figure to move(example: A8, english letters)";

		chessBoard::moveFigure(&Player);	// ������� ������
	}
}