#pragma once
#include "chessFigures.h"

// класс шахматной доски

enum cordAH {A = 0, B, C, D, E, F, G, H};

class chessBoard
{
	static chessBoardElement* field[8][8];	//шахматное поле в виде двумерного массива

	static void drawWhite(char emb,char Wteam);		// нарисовать белую €чейку
	static void drawBlack(char emb, char Wteam);	// нарисовать чЄрную  €чейку

public:
	static void startGame();	// начало игры и расстановка фигур
	static void drawBoard(team Player);	// графика шахматной доски
	static void drawCell(int x, int y);	// нарисовать одну €чейку шахматной доски
	static void moveFigure(team* playerTeam);	//	двинуть фигуру
};