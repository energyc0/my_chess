#pragma once
#include <iostream>

enum team { WHITE, BLACK };

class chessBoardElement	// абстрактный класс элементов шахматной доски
{
protected:
	int cordX;
	int cordY;
	char emblem;	// Отображение элемента на шахматной доске
	char TeamEmblem;
public:
	chessBoardElement(int x, int y)
	{
		cordX = x;
		cordY = y;
		emblem = '0';
		TeamEmblem = '0';
	}
	virtual char returnEmblem() const
	{
		return emblem;
	}
	virtual char returnTeam() const
	{
		return TeamEmblem;
	}
	virtual bool rightFigureMove(int McordX, int McordY) const = 0;	// правильность передвижения фигур
	virtual void changePlace(int McordX, int McordY)
	{
		cordX = McordX;
		cordY = McordY;
	}
};

/////////////////////////////////////////////////////

class chess_figure : public chessBoardElement	// абстрактный класс для фигур
{
public:
	chess_figure(int x, int y, team t) : chessBoardElement(x, y)
	{
		if (t == WHITE)
			TeamEmblem = char(254);		// команда белых
		else
			TeamEmblem = ' ';			// команда чёрных
	}
	virtual bool rightFigureMove(int McordX, int McordY) const = 0;
};

//////////////////////////////////////////////////////

class cell : public chessBoardElement	// шахматная клетка
{
public:
	cell(int x, int y) : chessBoardElement(x, y)
	{
		if (x % 2 == 0)
		{
			if (y % 2 == 0)
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
			if (y % 2 == 0)
			{
				emblem = char(177); // чёрный цвет
			}
			else
			{
				emblem = char(219); // белый цвет
			}
		}
		TeamEmblem = emblem;
	}
	bool rightFigureMove(int McordX, int McordY) const { return true; }
};

//////////////////////////////////

class pawn : public chess_figure	// пешка
{
public:
	pawn(int x, int y, team t) : chess_figure(x,y, t)
	{
		emblem = 'P';
	}
	bool rightFigureMove(int McordX, int McordY) const;
};

//////////////////////////////////

class rook : public chess_figure	// ладья
{
public:
	rook(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = 'R';
	}
	bool rightFigureMove(int McordX, int McordY) const;
};

//////////////////////////////////

class bishop : public chess_figure	// слон
{
public:
	bishop(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = 'B';
	}
	bool rightFigureMove(int McordX, int McordY) const;
};

//////////////////////////////////

class knight : public chess_figure	// конь
{
public:
	knight(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = 'K';
	}
	bool rightFigureMove(int McordX, int McordY) const;
};

//////////////////////////////////

class queen : public chess_figure	// королева
{
public:
	queen(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = 'Q';
	}
	bool rightFigureMove(int McordX, int McordY) const;
};

//////////////////////////////////

class king : public chess_figure	// король
{
public:
	king(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = char(253);
	}
	bool rightFigureMove(int McordX, int McordY) const;
};
