#pragma once
#include <iostream>

class chess_figure
{
protected:
	char emblem;	// Отображение фигуры на шахматной доске
public:
	char returnEmblem() const
	{
		return emblem;
	}
	void showFigure() const
	{
		std::cout << emblem;
	}
};

//////////////////////////////////

class cell : public chess_figure	// шахматная клетка
{
	enum color { WHITE, BLACK };
public:
	cell(int i, int j) : chess_figure()
	{
		if (i % 2 == 0)
		{
			if (j % 2 == 0)
			{
				emblem = char(219);	// белый цвет
			}
			else
			{
				emblem = char(177); // чёрный цвет
			}
		}
		else
		{
			if (j % 2 == 0)
			{
				emblem = char(177); // чёрный цвет
			}
			else
			{
				emblem = char(219); // белый цвет
			}
		}
	}
};

//////////////////////////////////

class pawn : public chess_figure	// пешка
{
public:
	pawn() : chess_figure()
	{
		emblem = 'P';
	}
};

//////////////////////////////////

class rook : public chess_figure	// ладья
{
public:
	rook() : chess_figure()
	{
		emblem = 'R';
	}
};

//////////////////////////////////

class bishop : public chess_figure	// слон
{
public:
	bishop() : chess_figure()
	{
		emblem = 'B';
	}
};

//////////////////////////////////

class knight : public chess_figure	// конь
{
public:
	knight() : chess_figure()
	{
		emblem = 'K';
	}
};

//////////////////////////////////

class queen : public chess_figure	// королева
{
public:
	queen() : chess_figure()
	{
		emblem = 'Q';
	}
};

//////////////////////////////////

class king : public chess_figure	// король
{
public:
	king() : chess_figure()
	{
		emblem = 'K';
	}
};
