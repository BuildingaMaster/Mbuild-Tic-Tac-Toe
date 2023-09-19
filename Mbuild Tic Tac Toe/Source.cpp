#include <iostream>

using namespace std;

void printInstructions()
{
	cout << "Welcome to Tic Tac Toe " << endl << endl;
	cout << "How To Play: " << endl;
	cout << "Tic Tac Toe is a game played on a 3 x 3 board. The rows will be labeled A, B, C" << endl;
	cout << "The columns are labeled 1 2 3. " << endl;
	cout << "There are two players, one player will be assigned the letter 'X' and the other will be assigned 'O'. ";
	cout << "The player who gets the first move of the game will be random. Each player will alternate one move at a time. " << endl;
	cout << "If a player enters an invalid spot / a spot already taken on the board, that player will be asked to re-enter their move on an available spot on the board. " << endl;
	cout << "The objective of the game is to get 3 'X's or 'O's in a row either horizontally, vertically, or diagonally. " << endl;
	cout << "If the board is filled and there is not a sequence of 3 'X's or 'O's in arow as stated above, the game ends in a tie. " << endl;
	cout << "You will have the option to restart the game or quit at the end of a game and at any point during an ongoing game. " << endl;
}