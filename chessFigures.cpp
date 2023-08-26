#include "chessFigures.h"
#include "chessBoard.h"

bool thereAlly(int cordX, int cordY, int McordX, int McordY)
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
	return true;
}

bool pawn::rightFigureMove(int McordX, int McordY) const	// правильность хода пешки
{
	return true;
}

///////////////////////////////

bool rook::rightFigureMove(int McordX, int McordY) const	// правильность хода ладьи
{
	int cordChange;
	if (!thereAlly(cordX, cordY, McordX, McordY))
	{
		return false;
	}
	if (McordY == cordY)	// если ладья движется вдоль 1-8
	{
		cordChange = McordX - cordX;
		if (cordChange > 0)
		{
			for (int i = 1; i < cordChange; i++)
			{
				if (chessBoard::field[cordX + i][cordY]->returnEmblem() != BlackCell || chessBoard::field[cordX + i][cordY]->returnEmblem() != WhiteCell)	// если на пути фигура, то ходить нельзя
				{
					std::cout << "\nThere is figure on the way";
					return false;
				}
			}
		}
		else
		{
			for (int i = -1; i > cordChange; i--)
			{
				if (chessBoard::field[cordX + i][cordY]->returnEmblem() != BlackCell || chessBoard::field[cordX + i][cordY]->returnEmblem() != WhiteCell)	// если на пути фигура, то ходить нельзя
				{
					std::cout << "\nThere is figure on the way";
					return false;
				}
			}
		}
		return true;
	}
	else if(McordX == cordX)		//если ладья движется вдоль A-H
	{
		cordChange = McordY - cordY;
		if (cordChange > 0)
		{
			for (int i = 1; i < cordChange;i++)
			{
				if (chessBoard::field[cordX][cordY + i]->returnEmblem() != BlackCell && chessBoard::field[cordX][cordY + i]->returnEmblem() != WhiteCell)	// если на пути фигура, то ходить нельзя
				{
					std::cout << "\nThere is figure on the way";
					return false;
				}
			}
		}
		else
		{
			for (int i = -1; i > cordChange; i--)
			{
				if (chessBoard::field[cordX][cordY + i]->returnEmblem() != BlackCell && chessBoard::field[cordX][cordY + i]->returnEmblem() != WhiteCell)	// если на пути фигура, то ходить нельзя
				{
					std::cout << "\nThere is figure on the way";
					return false;
				}
			}
		}
		return true;
	}
	else
	{
		std::cout << "\nYou can`t move like that";
		return false;
	}
}

///////////////////////////////

bool bishop::rightFigureMove(int McordX, int McordY) const	// правильность хода слона
{
	int tempX, tempY;
	if (!thereAlly(cordX, cordY, McordX, McordY))
	{
		return false;
	} 
	tempX = (cordX > McordX) ? cordX - McordX : McordX - cordX; // разница между x
	tempY = (cordY > McordY) ? cordY - McordY : McordY - cordY; // разница между y
	if (tempX == tempY)
	{
		tempX = McordX - cordX;
		tempY = McordY - cordY;

		if (tempX > 0 && tempY > 0)	// если положительная ось увеличивается
		{
			for (int i = 1; i < tempX; i++)
			{
				if (chessBoard::field[cordX + i][cordY + i]->returnEmblem() != BlackCell && chessBoard::field[cordX + i][cordY + i]->returnEmblem() != WhiteCell)
				{
					std::cout << "\nThere is a figure on the way";
					return false;
				}
			}
		}
		else if (tempX > 0 && tempY < 0)	// если x увеличивается, y уменьшается
		{
			for (int i = 1; i < tempX; i++)
			{
				if (chessBoard::field[cordX + i][cordY - i]->returnEmblem() != BlackCell && chessBoard::field[cordX + i][cordY - i]->returnEmblem() != WhiteCell)
				{
					std::cout << "\nThere is a figure on the way";
					return false;
				}
			}
		}
		else if (tempX < 0 && tempY > 0)	// если y увеличивается, x уменьшается
		{
			for (int i = 1; i < tempY; i++)
			{
				if (chessBoard::field[cordX - i][cordY + i]->returnEmblem() != BlackCell && chessBoard::field[cordX - i][cordY + i]->returnEmblem() != WhiteCell)
				{
					std::cout << "\nThere is a figure on the way";
					return false;
				}
			}
		}
		else	// если отрицательная ось увеличивается
		{
			for (int i = -1; i > tempX; i--)
			{
				if (chessBoard::field[cordX + i][cordY + i]->returnEmblem() != BlackCell && chessBoard::field[cordX + i][cordY + i]->returnEmblem() != WhiteCell)
				{	
					std::cout << "\nThere is a figure on the way";
					return false;
				}
			}
		}

		return true;
	}
	else
	{
		std::cout << "\nYou can`t move likt that";
		return false;
	}
}

///////////////////////////////

bool knight::rightFigureMove(int McordX, int McordY) const	// правильность хода коня
{
	if (!thereAlly(cordX, cordY, McordX, McordY))
	{
		return false;
	}
	int tempX, tempY;
	tempX = (cordX > McordX) ? cordX - McordX : McordX - cordX;	// разница между x
	tempY = (cordY > McordY) ? cordY - McordY : McordY - cordY; // разница между y

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