#include "TacBoard.h"
#include <iostream>
using namespace std;

int rowConvert(char toInt)
{
	switch (toInt)
	{
	case 'a':
	{
		return 0;
		break;
	}
	case 'A':
	{
		return 0;
		break;
	}
	case 'b':
	{
		return 1;
		break;
	}
	case 'B':
	{
		return 1;
		break;
	}
	case 'c':
	{
		return 2;
		break;
	}
	case 'C':
	{
		return 2;
		break;
	}
	default:
	{
		// Nothing will happen here
	}
	}
}
// Converts chars 'a' 'b' 'c' into readable integers for the BoardLayout array

TacBoard::TacBoard()
{
	Turn = 'X';
	BoardLayout[3][3];

	BoardLayout[0][0] = 'X';
	BoardLayout[1][1] = 'X';
	BoardLayout[2][2] = 'X';
}

char TacBoard::checkSpace(char Row, int Column)
{
	int intRow = rowConvert(Row);
	if (BoardLayout[intRow][Column-1] != '\0')
	{
		if (BoardLayout[intRow][Column-1] == x)
		{
			return 'X';
		}
		if (BoardLayout[intRow][Column-1] == o)
		{
			return 'O';
		}
	}
	else
	{
		return '\0';
	}
}
// Returns what letter currently occupies a specific space on the board ( row x column )
// Returns '\0' if the space is empty

void TacBoard::nextTurn()
{
	if (Turn == 'X')
	{
		Turn = 'O';
	}
	else
	{
		Turn = 'X';
	}
	return;
}
// Called after adding a space, switches to the next turn

void TacBoard::addSpace(char Row, int Column)
{
	if (checkSpace(Row, Column) != '\0')
	{
		int intRow = rowConvert(Row);
		BoardLayout[intRow][Column-1] = Turn;
		nextTurn();
	}
	else
	{
		return;
	}
}
// Adds an 'x' or an 'o' to the desired space in the array ( row x column )
// Halts if there is a char already in that space

void TacBoard::tempPrintBoard()
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << BoardLayout[i][j] << " ";
		}
		cout << endl;
	}
}