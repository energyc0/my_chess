#pragma once
#include "chessFigures.h"

// ����� ��������� �����

class chessBoard
{
	static chessBoardElement* field[8][8];	//��������� ���� � ���� ���������� �������
public:
	static void startGame();
	static void drawWhiteCell(char emb);
	static void drawBlackCell(char emb);
	static void drawBoard();

};