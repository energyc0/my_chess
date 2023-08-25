#pragma once
#include "chessFigures.h"

// ����� ��������� �����

enum cordAH {A = 0, B, C, D, E, F, G, H};

class chessBoard
{
	static chessBoardElement* field[8][8];	//��������� ���� � ���� ���������� �������

	static void drawWhite(char emb,char Wteam);		// ���������� ����� ������
	static void drawBlack(char emb, char Wteam);	// ���������� ������  ������

public:
	static void startGame();	// ������ ���� � ����������� �����
	static void drawBoard(team Player);	// ������� ��������� �����
	static void drawCell(int x, int y);	// ���������� ���� ������ ��������� �����
	static void moveFigure(team* playerTeam);	//	������� ������
};