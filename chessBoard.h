#pragma once
#include "chessFigures.h"

// ����� ��������� �����

class chessBoard
{
	static chess_figure* field[8][8];	//��������� ���� � ���� ���������� �������
public:
	static void startGame();
	static void drawWhiteCell(char emb);
	static void drawBlackCell(char emb);
	static void drawBoard();
};