#include "chessBoard.h"
#include <iostream>

chessBoardElement* chessBoard::field[8][8];

using namespace std;

void chessBoard::startGame()	// начало игры и расстановка фигур по местам
{
	team temp; // переменна€ определ€юща€ команду фигуры
	for (int y = 0; y < 8; y++)
	{
		if (y == 0 || y == 1)
			temp = BLACK;
		else
			temp = WHITE;
		for (int x = 0; x < 8; x++)
		{
			if (y == 0 || y == 7)
			{
				if (x == 0 || x == 7)
				{
					field[x][y] = new rook(x,y, temp);
				}
				else if (x == 1 || x == 6)
				{
					field[x][y] = new knight(x, y, temp);
				}
				else if (x == 2 || x == 5)
				{
					field[x][y] = new bishop(x, y, temp);
				}
				else if (x == 3)
				{
					if (y == 0)
					{
						field[x][y] = new queen(x, y, temp);
					}
					else
					{
						field[x][y] = new king(x, y, temp);
					}
				}
				else
				{
					if (y == 0)
					{
						field[x][y] = new king(x, y, temp);
					}
					else
					{
						field[x][y] = new queen(x, y, temp);
					}
				}
			}
			else if (y == 1 || y == 6)
			{
				field[x][y] = new pawn(x, y, temp);
			}
			else
			{
				field[x][y] = new cell(x, y);
			}
		}
	}
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//													√рафика																	 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

void chessBoard::drawWhite(char emb, char Wteam)	// нарисовать белую клетку с фигурой или без
{
	cout << char(219) << emb  << Wteam << char(219);
}

void chessBoard::drawBlack(char emb, char Wteam)	// нарисовать чЄрную клетку с фигурой или без
{
	cout << char(177) << emb  << Wteam << char(177);
}

void chessBoard::drawCell(int x, int y)
{
	if (x % 2 == 0)
	{
		if (y % 2 == 0)
		{
			chessBoard::drawWhite(field[x][y]->returnEmblem(), field[x][y]->returnTeam());
		}
		else
		{
			chessBoard::drawBlack(field[x][y]->returnEmblem(), field[x][y]->returnTeam());
		}
	}
	else
	{
		if (y % 2 == 0)
		{
			chessBoard::drawBlack(field[x][y]->returnEmblem(), field[x][y]->returnTeam());
		}
		else
		{

			chessBoard::drawWhite(field[x][y]->returnEmblem(), field[x][y]->returnTeam());
		}
	}
}

void chessBoard::drawBoard(team Player)	// консольна€ графика шахматной доски
{
	system("cls");
	for (int y = 0; y < 8; y++)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int x = 0; x < 8; x++)
			{
				if (k == 1)
				{
					chessBoard::drawCell(x, y);
					if (x == 7)
					{
						cout << " | " << char(65 + y);	// указатель координат A - H
					}
				}
				else
				{
					if (x % 2 == 0)
					{
						if (y % 2 == 0)
						{
							chessBoard::drawWhite(char(219), char(219));	// пуста€ бела€ клетка
						}
						else
						{
							chessBoard::drawBlack(char(177), char(177));	// пуста€ чЄрна€ клетка
						}
					}
					else
					{
						if (y % 2 == 0)
						{
							chessBoard::drawBlack(char(177), char(177));	// пуста€ чЄрна€ клетка
						}
						else
						{

							chessBoard::drawWhite(char(219), char(219));  // пуста€ бела€ клетка
						}
					}
					if (x == 7)
					{
						cout << " | ";
					}
				}
			}
			cout << endl;
		}
	}
	for (int i = 0; i < 33; i++)	// отделитель от координат
		cout << "_";
	cout << "|		'P' is pawn, 'R' is rook, 'B' is bishop, 'K' is knight, 'Q' is queen, '"<< char(253) <<"' is king";		// пам€тка
	cout << "\n 1   2   3   4   5   6   7   8			" << "'" << char(254) << "' is white player`s figure, ' ' is black player`s figure\n\n";	// указатель координат 1 - 8
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//													”правление																 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

void chessBoard::moveFigure(team* playerTeam)		// движение фигуры или выход из игры
{
	string ans;
	char teamEmb;
	int FcordX, FcordY, McordX, McordY;	// координаты фигуры и координаты места передвижени€
	while (true)
	{
		cin.clear();
		cout << "\nEnter the command: ";
		ws(cin) >> ans;
		if (ans == "exit")	// пользователь выходит
		{
			exit(0);
		}
		else if (ans.length() != 2)		// проверка на неизвестную команду
		{
			cin.clear(ios::badbit);
		}
		else                            // проверка на неизвестную команду
		{
			if (ans[0] < 'A' || ans[0] > 'H')
				cin.clear(ios::badbit);
			else if (ans[1] < '1' || ans[1] > '8')
				cin.clear(ios::badbit);
		}
		if (cin.bad())					// eсли неизвестна€ команда
			cout << "Undefined command, try again";
		else
		{
			FcordY = ans[0] - 65;
			FcordX = ans[1] - 49;
			if (*playerTeam == WHITE)
				teamEmb = char(254);
			else
				teamEmb = ' ';
			if (field[FcordX][FcordY]->returnTeam() == teamEmb)	// проверка на соответствие команды игрока и фигуры
				break;
			else
				if (field[FcordX][FcordY]->returnEmblem() == char(177) || field[FcordX][FcordY]->returnEmblem() == char(219))	// если пуста€ клетка
					cout << "There is no figure, try again";
				else
					cout << "This is the opponent`s figure, try again";		// или фигура противника
		}
		cin.ignore(100, '\n');
	}

	cin.ignore(100, '\n');

	while (true)
	{
		cin.clear();
		cout << "\nEnter coordinates to move(enter 'cancel' to cancel selected figure): ";
		ws(cin) >> ans;
		if (ans == "cancel")	// пользователь выходит
		{
			return;
		}
		else if (ans.length() != 2)		// проверка на неизвестную команду
		{
			cin.clear(ios::badbit);
		}
		else                            // проверка на неизвестную команду
		{
			if (ans[0] < 'A' || ans[0] > 'H')
				cin.clear(ios::badbit);
			else if (ans[1] < '1' || ans[1] > '8')
				cin.clear(ios::badbit);
		}
		if (cin.bad())					// eсли неизвестна€ команда
			cout << "Undefined command, try again";
		McordY = ans[0] - 65;
		McordX = ans[1] - 49;
		if (field[FcordX][FcordY]->rightFigureMove(McordX, McordY))
		{
			chessBoardElement* tempptr;
			tempptr = field[McordX][McordY];
			if (field[McordX][McordY]->returnEmblem() == 'K')	// если убит чЄй-то король
			{
				field[McordX][McordY] = field[FcordX][FcordY];
				field[FcordX][FcordY] = new cell(FcordX, FcordY);
				delete tempptr;
				chessBoard::drawBoard(*playerTeam);
				if (field[McordX][McordY]->returnTeam() == ' ') // если корол€ убила чЄрна€ фигура
				{
					cout << "Black player`s win";
				}
				else
				{
					cout << "White player`s win";
				}
				exit(0);
			}
			else
			{
				field[McordX][McordY] = field[FcordX][FcordY];
				field[FcordX][FcordY] = new cell(FcordX, FcordY);
				delete tempptr;
				field[McordX][McordY]->changePlace(McordX, McordY);
				if (*playerTeam == WHITE)
					*playerTeam = BLACK;
				else
					*playerTeam = WHITE;
				break;
			}
			cin.ignore(100, '\n');
		}
	}
}