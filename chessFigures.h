#pragma once
#include <iostream>

enum team { WHITE, BLACK };

const char KingEmblem = char(253);
const char QueenEmblem = 'Q';
const char PawnEmblem = 'P';
const char RookEmblem = 'R';
const char BishopEmblem = 'B';
const char KnightEmblem = 'K';
const char BlackCell = char(177);
const char WhiteCell = char(219);

class chessBoardElement	// ����������� ����� ��������� ��������� �����
{
protected:
	int cordX;
	int cordY;
	char emblem;	// ����������� �������� �� ��������� �����
	char TeamEmblem;
public:
	chessBoardElement()
	{
		cordX = 0; cordY = 0; emblem = ' '; TeamEmblem = ' ';
	}
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
	virtual bool rightFigureMove(int McordX, int McordY) const = 0;	// ������������ ������������ �����
	virtual void changePlace(int McordX, int McordY)
	{
		cordX = McordX;
		cordY = McordY;
	}
};

/////////////////////////////////////////////////////

class chess_figure : public chessBoardElement	// ����������� ����� ��� �����
{
public:
	chess_figure()
	{
		cordX = 0; cordY = 0; emblem = ' '; TeamEmblem = ' ';
	}
	chess_figure(int x, int y, team t) : chessBoardElement(x, y)
	{
		if (t == WHITE)
			TeamEmblem = char(254);		// ������� �����
		else
			TeamEmblem = ' ';			// ������� ������
	}
	virtual bool rightFigureMove(int McordX, int McordY) const = 0;
};

//////////////////////////////////////////////////////

class cell : public chessBoardElement	// ��������� ������
{
public:
	cell(int x, int y) : chessBoardElement(x, y)
	{
		if (x % 2 == 0)
		{
			if (y % 2 == 0)
			{
				emblem = WhiteCell;	// ����� ����
			}
			else
			{
				emblem = BlackCell; // ������ ����
			}
		}
		else
		{
			if (y % 2 == 0)
			{
				emblem = BlackCell; // ������ ����
			}
			else
			{
				emblem = WhiteCell; // ����� ����
			}
		}
		TeamEmblem = emblem;
	}
	bool rightFigureMove(int McordX, int McordY) const { return true; }
};

//////////////////////////////////

class pawn : public chess_figure	// �����
{
	int countMoves;
public:
	pawn(int x, int y, team t) : chess_figure(x,y, t)
	{
		emblem = PawnEmblem;
		countMoves = 0;
	}
	void increaseMoves();
	int returnMoves();
	bool rightFigureMove(int McordX, int McordY) const;
};

//////////////////////////////////

class rook : public chess_figure	// �����
{
public:
	rook(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = RookEmblem;
	}
	bool rightFigureMove(int McordX, int McordY) const;
};

//////////////////////////////////

class bishop : public chess_figure	// ����
{
public:
	bishop(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = BishopEmblem;
	}
	bool rightFigureMove(int McordX, int McordY) const;
};

//////////////////////////////////

class knight : public chess_figure	// ����
{
public:
	knight(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = KnightEmblem;
	}
	bool rightFigureMove(int McordX, int McordY) const;
};

//////////////////////////////////

class queen : public chess_figure	// ��������
{
public:
	queen(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = QueenEmblem;
	}
	bool rightFigureMove(int McordX, int McordY) const;
};

//////////////////////////////////

class king : public chess_figure	// ������
{
public:
	king(int x, int y, team t) : chess_figure(x,y,t)
	{
		emblem = char(253);
	}
	bool rightFigureMove(int McordX, int McordY) const;
};
