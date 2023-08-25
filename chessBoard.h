#pragma once
#include "chessFigures.h"

// ����� ��������� �����

class chessBoard
{
	static void drawWhite(char emb,char Wteam);		// ���������� ����� ������
	static void drawBlack(char emb, char Wteam);	// ���������� ������  ������

public:
	static chessBoardElement* field[8][8];	//��������� ���� � ���� ���������� �������
	static void startGame();	// ������ ���� � ����������� �����
	static void drawBoard(team Player);	// ������� ��������� �����
	static void drawCell(int x, int y);	// ���������� ���� ������ ��������� �����
	static void moveFigure(team* playerTeam);	//	������� ������
};
chessBoardElement chessBoard::field[8][8];