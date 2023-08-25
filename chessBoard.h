#pragma once
#include "chessFigures.h"

// ����� ��������� �����

class chessBoard
{
	static chessBoardElement* field[8][8];	//��������� ���� � ���� ���������� �������

	static void drawWhite(char emb,char Wteam);
	static void drawBlack(char emb, char Wteam);

public:
	static void startGame();
	static void drawBoard();
	static void drawCell(int x, int y);
};