#include "chessFigures.h"
#include "chessBoard.h"

bool pawn::rightFigureMove(int McordX, int McordY) const	// правильность хода пешки
{
	return true;
}

///////////////////////////////

bool rook::rightFigureMove(int McordX, int McordY) const	// правильность хода пешки ладьи
{
	return true;
}

///////////////////////////////

bool bishop::rightFigureMove(int McordX, int McordY) const	// правильность хода слона
{
	return true;
}

///////////////////////////////

bool knight::rightFigureMove(int McordX, int McordY) const	// правильность хода коня
{
	if (chessBoard::field[cordX][cordY]->returnTeam() == ' ')
	{
		if (chessBoard::field[McordX][McordY]->returnTeam() == ' ')
		{
			std::cout << "\nCan`t beat your figure";
			return false;
		}
	}
	else
	{
		if (chessBoard::field[McordX][McordY]->returnTeam() == char(254))
		{
			std::cout << "\nCan`t beat your figure";
			return false;
		}
	}
	int tempX, tempY;
	if (cordX > McordX)				//разница между х
	{
		tempX = cordX - McordX;
	}
	else
	{
		tempX = McordX - cordX;
	}
	if (cordY > McordY)				//разница между у
	{
		tempY = cordY - McordY;
	}
	else
	{
		tempY = McordY - cordY;
	}

	if ((tempX == 2 && tempY == 1) || (tempX == 1 && tempY == 2))
		return true;
	else
	{
		std::cout << "\nYou can`t move like that";
		return false;
	}
}

///////////////////////////////

bool queen::rightFigureMove(int McordX, int McordY) const	// правильность хода королевы
{
	return true;
}

///////////////////////////////

bool king::rightFigureMove(int McordX, int McordY) const	// правильность хода короля
{
	return true;
}