#pragma once
#include "chessFigures.h"

// ����� ��������� �����

class chessBoard
{
	static chess_figure* field[8][8];	//��������� ���� � ���� ���������� �������
public:
	static void startGame();
	static void drawWhiteCell();
	static void drawBlackCell();
	static void drawBoard();
};