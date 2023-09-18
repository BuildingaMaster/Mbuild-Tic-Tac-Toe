// Mbuild Tic Tac Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>

#include "TacBoard.h"
#include "TerminalDisplay.h"

using namespace std;

char firstMove()
{
	int randNum = rand() % 2;
	
	if (randNum == 1)
	{
		return 'X';
	}
	else
	{
		return 'O';
	}
}
void printInstructions()
{
	cout << "Welcome to Tic Tac Toe " << endl << endl;
	cout << "How To Play: " << endl;
	cout << "Tic Tac Toe is a game played on a 3 x 3 TicTacToe. The rows will be labeled A, B, C" << endl;
	cout << "The columns are labeled 1 2 3. " << endl;
	cout << "There are two players, one player will be assigned the letter 'X' and the other will be assigned 'O'." << endl;
	cout << "The player who gets the first move of the game will be random." << endl;
	cout << "Each player will alternate one move at a time. " << endl;
	cout << "If a player enters an invalid spot / a spot already taken on the board, that player will be asked to re-enter their move on an available spot on the TicTacToe. " << endl;
	cout << "The objective of the game is to get 3 'X's or 'O's in a row either horizontally, vertically, or diagonally. " << endl;
	cout << "If the board is filled and there is not a sequence of 3 'X's or 'O's in arow as stated above, the game ends in a tie. " << endl;
	cout << "You will have the option to restart the game or quit at the end of a game and at any point during an ongoing game. " << endl;
}

int main()
{
	srand(time(NULL)); // creating to make a "real" random first move

	TacBoard TicTacToe;
	// printInstructions();
    cout << "[Master Builders Tic Tac Toe]" << endl;
    string nothing;
    TicTacToe.printBoard();
    cout << "Type 'win' to win!" << endl; 
    cin >> nothing; // Just to freeze.
    TicTacToe.BoardGUI.board_status['A']['3'] = TicTacToe.BoardGUI.board_status['B']['3'] = TicTacToe.BoardGUI.board_status['C']['3'] = TacBoard::PLAYER_X;
    TicTacToe.printBoard();
    cout << "Real Player won: " << TicTacToe.checkPlayerWin() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file