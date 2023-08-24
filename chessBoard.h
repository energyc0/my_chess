#pragma once
#include "chessFigures.h"

// класс шахматной доски

class chessBoard
{
	static chess_figure* field[8][8];	//шахматное поле в виде двумерного массива
public:
	static void startGame();
	static void drawWhiteCell(char emb);
	static void drawBlackCell(char emb);
	static void drawBoard();
};