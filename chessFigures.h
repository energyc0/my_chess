#pragma once
#include <iostream>

class chess_figure
{
protected:
	char emblem;	// ?????? ??????????? ?????? ?? ??????? ????
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

class cell : public chess_figure
{
	enum color { WHITE, BLACK };
public:
	cell(int i, int j) : chess_figure()
	{
		if (i % 2 == 0)
		{
			if (j % 2 == 0)
			{
				emblem = char(219);
			}
			else
			{
				emblem = char(177);
			}
		}
		else
		{
			if (j % 2 == 0)
			{
				emblem = char(177);
			}
			else
			{
				emblem = char(219);
			}
		}
	}
};

//////////////////////////////////

class pawn : public chess_figure	// ?????
{
public:
	pawn() : chess_figure()
	{
		emblem = 'P';
	}
};

//////////////////////////////////

class rook : public chess_figure	// ?????
{
public:
	rook() : chess_figure()
	{
		emblem = 'R';
	}
};

//////////////////////////////////

class bishop : public chess_figure	// ????
{
public:
	bishop() : chess_figure()
	{
		emblem = 'B';
	}
};

//////////////////////////////////

class knight : public chess_figure	// ????
{
public:
	knight() : chess_figure()
	{
		emblem = 'K';
	}
};

//////////////////////////////////

class queen : public chess_figure	// ????????
{
public:
	queen() : chess_figure()
	{
		emblem = 'Q';
	}
};

//////////////////////////////////

class king : public chess_figure	// ??????
{
public:
	king() : chess_figure()
	{
		emblem = 'K';
	}
};
