#pragma once
#include <iostream>

enum team { WHITE, BLACK };

class chessBoardElement
{
protected:
	int cordX;
	int cordY;
	char emblem;	// ����������� �������� �� ��������� �����
public:
	chessBoardElement(int x, int y)
	{
		cordX = x;
		cordY = y;
	}
	char returnEmblem() const
	{
		return emblem;
	}
	void showFigure() const
	{
		std::cout << emblem;
	}
};

class chess_figure : public chessBoardElement
{
protected:
	team figureTeam;
public:
	chess_figure(int x, int y, team t) : chessBoardElement(x, y)
	{
		figureTeam = t;
	}
};

//////////////////////////////////

class cell : public chessBoardElement	// ��������� ������
{
public:
	cell(int x, int y) : chessBoardElement(x, y)
	{
		if (x % 2 == 0)
		{
			if (y % 2 == 0)
			{
				emblem = char(219);	// ����� ����
			}
			else
			{
				emblem = char(177); // ������ ����
			}
		}
		else
		{
			if (y % 2 == 0)
			{
				emblem = char(177); // ������ ����
			}
			else
			{
				emblem = char(219); // ����� ����
			}
		}
	}
};

//////////////////////////////////

class pawn : public chess_figure	// �����
{
public:
	pawn(int x, int y, team t) : chess_figure(x,y, t)
	{
		emblem = 'P';
	}
};

//////////////////////////////////

class rook : public chess_figure	// �����
{
public:
	rook(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = 'R';
	}
};

//////////////////////////////////

class bishop : public chess_figure	// ����
{
public:
	bishop(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = 'B';
	}
};

//////////////////////////////////

class knight : public chess_figure	// ����
{
public:
	knight(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = 'K';
	}
};

//////////////////////////////////

class queen : public chess_figure	// ��������
{
public:
	queen(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = 'Q';
	}
};

//////////////////////////////////

class king : public chess_figure	// ������
{
public:
	king(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = 'K';
	}
};
