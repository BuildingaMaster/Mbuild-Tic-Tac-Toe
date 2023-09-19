#pragma once
class TacBoard
{
public:
	// Stored moves
	char x = 'X';
	char o = 'O';

	// Pointers to the X and O characters
	char* setX = &x;
	char* setO = &o;

	// Stores pointer for which turn it currently is
	char Turn;

	// Default Constructor

	TacBoard();

	void addSpace(char Row, int Column);
	char checkSpace(char Row, int Column);
	void nextTurn();

	// Temporary printing function to test the functionality of the game

	void tempPrintBoard();

private:
	char BoardLayout[3][3];
};

