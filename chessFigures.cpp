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

bool pawn::rightFigureMove(int McordX, int McordY) const	// ������������ ���� �����
{
	if (!thereAlly(cordX, cordY, McordX, McordY))	// ���� ������ ���� ������ 
	{
		return false;
	}
	team tempTeam = (chessBoard::field[cordX][cordY]->returnTeam() == ' ') ? BLACK : WHITE;	// ���� ������� ����� �����
	pawn* tempptr = new pawn(cordX, cordY, tempTeam);	// ��������� ���������� �����, ������� ���� ���������
	int tempX, tempY; // ������� ����� x � �
	tempY = McordY - cordY; // ������� ����� x
	tempX = McordX - cordX; // ������� ����� y
	if (tempptr->returnTeam() == ' ')	// ������� ������
	{
		if (((tempX == 0 && tempY == 1)))	// ���� ����� ��������� ������
		{
			if (chessBoard::field[McordX][McordY]->returnEmblem() != WhiteCell && chessBoard::field[McordX][McordY]->returnEmblem() != BlackCell)	// ���� ������� �� ������ ������
			{
				std::cout << "\nYou can`t move like that";
				return false;
			}
		}
		else if ((tempX == tempY) && (tempX == 1 || tempX == -1))	// ���� ����� ���� ����������
		{
			if(!((chessBoard::field[McordX][McordY]->returnTeam() != chessBoard::field[cordX][cordY]->returnTeam()) && (chessBoard::field[McordX][McordY]->returnEmblem() != WhiteCell && chessBoard::field[McordX][McordY]->returnEmblem() != BlackCell))) // ���� � ���������������� ������ ������
			{
				std::cout << "\nYou can`t move like that";
				return false;
			}
		}
		else if (tempX == 0 && tempY == 2 && tempptr->returnMoves() == 0)	// ���� ����� ������ ������ ���
		{
			if ((chessBoard::field[McordX][McordY]->returnEmblem() != WhiteCell && chessBoard::field[McordX][McordY]->returnEmblem() != BlackCell) && (chessBoard::field[McordX][McordY -1 ]->returnEmblem() != WhiteCell && chessBoard::field[McordX][McordY - 1]->returnEmblem() != BlackCell))	// ���� ������� �� ������ ������
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
	else	// ������� �����
	{
		
	}
	tempptr->countMoves++;	// ��������� ����� ����� �����
	return true;
}

///////////////////////////////

bool rook::rightFigureMove(int McordX, int McordY) const	// ������������ ���� �����
{
	int cordChange;
	if (!thereAlly(cordX, cordY, McordX, McordY))	// ���� ������ ���� ������ 
	{
		return false;
	}
	if (McordY == cordY)	// ���� ����� �������� ����� 1-8
	{
		cordChange = McordX - cordX;
		if (cordChange > 0)
		{
			for (int i = 1; i < cordChange; i++)
			{
				if (chessBoard::field[cordX + i][cordY]->returnEmblem() != BlackCell && chessBoard::field[cordX + i][cordY]->returnEmblem() != WhiteCell)	// ���� �� ���� ������, �� ������ ������
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
				if (chessBoard::field[cordX + i][cordY]->returnEmblem() != BlackCell && chessBoard::field[cordX + i][cordY]->returnEmblem() != WhiteCell)	// ���� �� ���� ������, �� ������ ������
				{
					std::cout << "\nThere is figure on the way";
					return false;
				}
			}
		}
		return true;
	}
	else if(McordX == cordX)		//���� ����� �������� ����� A-H
	{
		cordChange = McordY - cordY;
		if (cordChange > 0)
		{
			for (int i = 1; i < cordChange;i++)
			{
				if (chessBoard::field[cordX][cordY + i]->returnEmblem() != BlackCell && chessBoard::field[cordX][cordY + i]->returnEmblem() != WhiteCell)	// ���� �� ���� ������, �� ������ ������
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
				if (chessBoard::field[cordX][cordY + i]->returnEmblem() != BlackCell && chessBoard::field[cordX][cordY + i]->returnEmblem() != WhiteCell)	// ���� �� ���� ������, �� ������ ������
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

bool bishop::rightFigureMove(int McordX, int McordY) const	// ������������ ���� �����
{
	int tempX, tempY;
	if (!thereAlly(cordX, cordY, McordX, McordY))	// ���� ������ ���� ������ 
	{
		return false;
	} 
	tempX = (cordX > McordX) ? cordX - McordX : McordX - cordX; // ������� ����� x
	tempY = (cordY > McordY) ? cordY - McordY : McordY - cordY; // ������� ����� y
	if (tempX == tempY)
	{
		tempX = McordX - cordX;
		tempY = McordY - cordY;

		if (tempX > 0 && tempY > 0)	// ���� ������������� ��� �������������
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
		else if (tempX > 0 && tempY < 0)	// ���� x �������������, y �����������
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
		else if (tempX < 0 && tempY > 0)	// ���� y �������������, x �����������
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
		else	// ���� ������������� ��� �������������
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

bool knight::rightFigureMove(int McordX, int McordY) const	// ������������ ���� ����
{
	if (!thereAlly(cordX, cordY, McordX, McordY))	// ���� ������ ���� ������ 
	{
		return false;
	}
	int tempX, tempY;
	tempX = (cordX > McordX) ? cordX - McordX : McordX - cordX;	// ������� ����� x
	tempY = (cordY > McordY) ? cordY - McordY : McordY - cordY; // ������� ����� y

	if ((tempX == 2 && tempY == 1) || (tempX == 1 && tempY == 2))
		return true;
	else
	{
		std::cout << "\nYou can`t move like that";
		return false;
	}
}

///////////////////////////////

bool queen::rightFigureMove(int McordX, int McordY) const	// ������������ ���� ��������
{
	int tempX,tempY;
	team tempTeam = (TeamEmblem == ' ') ? BLACK : WHITE;
	tempX = (cordX > McordX) ? cordX - McordX : McordX - cordX; // ������� ����� x
	tempY = (cordY > McordY) ? cordY - McordY : McordY - cordY; // ������� ����� y
	if (tempX == 0 || tempY == 0)	// ���� ����� ��� �����
	{
		rook* tempRook = new rook(cordX, cordY, tempTeam);
		if (tempRook->rightFigureMove(McordX, McordY))	// �������� �� ������������ ����
		{
			delete tempRook;
			return true;
		}
		delete tempRook;
		return false;
	}
	else if (tempX == tempY)			// ���� ����� ��� ����
	{
		bishop* tempBishop = new bishop(cordX, cordY, tempTeam);
		if (tempBishop->rightFigureMove(McordX, McordY))	// �������� �� ������������ ����
		{
			delete tempBishop;
			return true;
		}
		delete tempBishop;
		return false;
	}
	else													// ���� ����� ���-�� �����
	{
		std::cout << "\nYou can`t move like that";
		return false;
	}
}

///////////////////////////////

bool king::rightFigureMove(int McordX, int McordY) const	// ������������ ���� ������
{
	if (!thereAlly(cordX, cordY, McordX, McordY))	// ���� ������ ���� ������ 
	{
		return false;
	}
	int tempX, tempY;
	tempX = (cordX > McordX) ? cordX - McordX : McordX - cordX; // ������� ����� x
	tempY = (cordY > McordY) ? cordY - McordY : McordY - cordY; // ������� ����� y
	if (tempY > 1 || tempX > 1)
	{
		std::cout << "\nYou can`t move like that";
		return false;
	}
	return true;
}