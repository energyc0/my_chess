#include "chessBoard.h"
#include <iostream>

chessBoardElement* chessBoard::field[8][8];

using namespace std;

void chessBoard::startGame()	// ������ ���� � ����������� ����� �� ������
{
	team temp; // ���������� ������������ ������� ������
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
//													�������																	 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

void chessBoard::drawWhite(char emb, char Wteam)	// ���������� ����� ������ � ������� ��� ���
{
	cout << char(219) << emb  << Wteam << char(219);
}

void chessBoard::drawBlack(char emb, char Wteam)	// ���������� ������ ������ � ������� ��� ���
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

void chessBoard::drawBoard(team Player)	// ���������� ������� ��������� �����
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
						cout << " | " << char(65 + y);	// ��������� ��������� A - H
					}
				}
				else
				{
					if (x % 2 == 0)
					{
						if (y % 2 == 0)
						{
							chessBoard::drawWhite(char(219), char(219));	// ������ ����� ������
						}
						else
						{
							chessBoard::drawBlack(char(177), char(177));	// ������ ������ ������
						}
					}
					else
					{
						if (y % 2 == 0)
						{
							chessBoard::drawBlack(char(177), char(177));	// ������ ������ ������
						}
						else
						{

							chessBoard::drawWhite(char(219), char(219));  // ������ ����� ������
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
	for (int i = 0; i < 33; i++)	// ���������� �� ���������
		cout << "_";
	cout << "|		'"<< PawnEmblem << "' is pawn, '" << RookEmblem <<"' is rook, '" << RookEmblem <<"' is bishop, '"<<KnightEmblem <<"' is knight, '" << QueenEmblem<<"' is queen, '" << KingEmblem << "' is king";		// �������
	cout << "\n 1   2   3   4   5   6   7   8			" << "'" << char(254) << "' is white player`s figure, ' ' is black player`s figure\n\n";	// ��������� ��������� 1 - 8
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//													����������																 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

void chessBoard::moveFigure(team* playerTeam)		// �������� ������ ��� ����� �� ����
{
	string ans;
	char teamEmb;
	int FcordX, FcordY, McordX, McordY;	// ���������� ������ � ���������� ����� ������������
	while (true)
	{
		cin.clear();
		cout << "\nEnter the command: ";
		ws(cin) >> ans;
		if (ans == "exit")	// ������������ �������
		{
			exit(0);
		}
		else if (ans.length() != 2)		// �������� �� ����������� �������
		{
			cin.clear(ios::badbit);
		}
		else                            // �������� �� ����������� �������
		{
			if ((ans[0] < 'A' || ans[0] > 'H') && (ans[0] < 'a' || ans[0] > 'h'))
				cin.clear(ios::badbit);
			else if (ans[1] < '1' || ans[1] > '8')
				cin.clear(ios::badbit);
		}
		if (cin.bad())					// e��� ����������� �������
			cout << "Undefined command, try again";
		else
		{
			ans[0] = tolower(ans[0]);
			FcordY = ans[0] - 97;
			FcordX = ans[1] - 49;
			if (*playerTeam == WHITE)
				teamEmb = char(254);
			else
				teamEmb = ' ';
			if (field[FcordX][FcordY]->returnTeam() == teamEmb)	// �������� �� ������������ ������� ������ � ������
				break;
			else
				if (field[FcordX][FcordY]->returnEmblem() == char(177) || field[FcordX][FcordY]->returnEmblem() == char(219))	// ���� ������ ������
					cout << "There is no figure, try again";
				else
					cout << "This is the opponent`s figure, try again";		// ��� ������ ����������
		}
		cin.ignore(100, '\n');
	}

	cin.ignore(100, '\n');

	while (true)
	{
		cin.clear();
		cout << "\nEnter coordinates to move(enter 'cancel' to cancel selected figure): ";
		ws(cin) >> ans;
		if (ans == "cancel")	// ������������ �������
		{
			return;
		}
		else if (ans.length() != 2)		// �������� �� ����������� �������
		{
			cin.clear(ios::badbit);
		}
		else                            // �������� �� ����������� �������
		{
			if ((ans[0] < 'A' || ans[0] > 'H') && (ans[0] < 'a' || ans[0] > 'h'))
				cin.clear(ios::badbit);
			else if (ans[1] < '1' || ans[1] > '8')
				cin.clear(ios::badbit);
		}
		ans[0] = tolower(ans[0]);
		McordY = ans[0] - 97;
		McordX = ans[1] - 49;
		if ((McordX == FcordX) && (McordY == FcordY))	// ���� ������� ���� � �� �� ����������
		{
			cout << "You need to move your figure";
		}
		else if (cin.bad())					// e��� ����������� �������
		{
			cout << "Undefined command, try again";
		}
		else if (field[FcordX][FcordY]->rightFigureMove(McordX, McordY))
		{
			chessBoardElement* tempptr;
			tempptr = field[McordX][McordY];
			if (field[McordX][McordY]->returnEmblem() == KingEmblem)	// ���� ���� ���-�� ������
			{
				field[McordX][McordY] = field[FcordX][FcordY];
				field[FcordX][FcordY] = new cell(FcordX, FcordY);
				delete tempptr;
				chessBoard::drawBoard(*playerTeam);
				if (field[McordX][McordY]->returnTeam() == ' ') // ���� ������ ����� ������ ������
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