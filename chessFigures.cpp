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

void pawn::increaseMoves()
{
	countMoves++;
}
int pawn::returnMoves()
{
	return countMoves;
}

bool pawn::rightFigureMove(int McordX, int McordY) const	// правильность хода пешки
{
	if (!thereAlly(cordX, cordY, McordX, McordY))	// если бьётся своя фигура 
	{
		return false;
	}
	team tempTeam = (chessBoard::field[cordX][cordY]->returnTeam() == ' ') ? BLACK : WHITE;	// дать команду новой пешке
	pawn* tempptr = new pawn(cordX, cordY, tempTeam);	// временная переменная пешки, которую надо проверить
	int tempX, tempY; // разница между x и у
	tempY = McordY - cordY; // разница между x
	tempX = McordX - cordX; // разница между y
	if (tempptr->returnTeam() == ' ')	// команда чёрных
	{
		if (((tempX == 0 && tempY == 1)))	// если пешка двигается вперед
		{
			if (chessBoard::field[McordX][McordY]->returnEmblem() != WhiteCell && chessBoard::field[McordX][McordY]->returnEmblem() != BlackCell)	// если впереди не пустая клетка
			{
				std::cout << "\nYou can`t move like that";
				return false;
			}
		}
		else if ((tempX == tempY) && (tempX == 1 || tempX == -1))	// если пешка бъёт противника
		{
			if(!((chessBoard::field[McordX][McordY]->returnTeam() != chessBoard::field[cordX][cordY]->returnTeam()) && (chessBoard::field[McordX][McordY]->returnEmblem() != WhiteCell && chessBoard::field[McordX][McordY]->returnEmblem() != BlackCell))) // если в действительности бьётся фигура
			{
				std::cout << "\nYou can`t move like that";
				return false;
			}
		}
		else if (tempX == 0 && tempY == 2 && tempptr->returnMoves() == 0)	// если пешка делает первый шаг
		{
			if ((chessBoard::field[McordX][McordY]->returnEmblem() != WhiteCell && chessBoard::field[McordX][McordY]->returnEmblem() != BlackCell) && (chessBoard::field[McordX][McordY -1 ]->returnEmblem() != WhiteCell && chessBoard::field[McordX][McordY - 1]->returnEmblem() != BlackCell))	// если впереди не пустая клетка
			{
				std::cout << "\nYou can`t move like that";
				return false;
			}
		}
		else
		{
			std::cout << "\nYou can`t move like that";
			return false;
		}

	}
	else	// команда белых
	{
		
	}
	tempptr->countMoves++;	// увеличили число ходов пешки
	return true;
}

///////////////////////////////

bool rook::rightFigureMove(int McordX, int McordY) const	// правильность хода ладьи
{
	int cordChange;
	if (!thereAlly(cordX, cordY, McordX, McordY))	// если бьётся своя фигура 
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
				if (chessBoard::field[cordX + i][cordY]->returnEmblem() != BlackCell && chessBoard::field[cordX + i][cordY]->returnEmblem() != WhiteCell)	// если на пути фигура, то ходить нельзя
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
				if (chessBoard::field[cordX + i][cordY]->returnEmblem() != BlackCell && chessBoard::field[cordX + i][cordY]->returnEmblem() != WhiteCell)	// если на пути фигура, то ходить нельзя
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
	if (!thereAlly(cordX, cordY, McordX, McordY))	// если бьётся своя фигура 
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
		std::cout << "\nYou can`t move like that";
		return false;
	}
}

///////////////////////////////

bool knight::rightFigureMove(int McordX, int McordY) const	// правильность хода коня
{
	if (!thereAlly(cordX, cordY, McordX, McordY))	// если бьётся своя фигура 
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
	int tempX,tempY;
	team tempTeam = (TeamEmblem == ' ') ? BLACK : WHITE;
	tempX = (cordX > McordX) ? cordX - McordX : McordX - cordX; // разница между x
	tempY = (cordY > McordY) ? cordY - McordY : McordY - cordY; // разница между y
	if (tempX == 0 || tempY == 0)	// если ходит как ладья
	{
		rook* tempRook = new rook(cordX, cordY, tempTeam);
		if (tempRook->rightFigureMove(McordX, McordY))	// проверка на правильность хода
		{
			delete tempRook;
			return true;
		}
		delete tempRook;
		return false;
	}
	else if (tempX == tempY)			// если ходит как слон
	{
		bishop* tempBishop = new bishop(cordX, cordY, tempTeam);
		if (tempBishop->rightFigureMove(McordX, McordY))	// проверка на правильность хода
		{
			delete tempBishop;
			return true;
		}
		delete tempBishop;
		return false;
	}
	else													// если ходит как-то иначе
	{
		std::cout << "\nYou can`t move like that";
		return false;
	}
}

///////////////////////////////

bool king::rightFigureMove(int McordX, int McordY) const	// правильность хода короля
{
	if (!thereAlly(cordX, cordY, McordX, McordY))	// если бьётся своя фигура 
	{
		return false;
	}
	int tempX, tempY;
	tempX = (cordX > McordX) ? cordX - McordX : McordX - cordX; // разница между x
	tempY = (cordY > McordY) ? cordY - McordY : McordY - cordY; // разница между y
	if (tempY > 1 || tempX > 1)
	{
		std::cout << "\nYou can`t move like that";
		return false;
	}
	return true;
}