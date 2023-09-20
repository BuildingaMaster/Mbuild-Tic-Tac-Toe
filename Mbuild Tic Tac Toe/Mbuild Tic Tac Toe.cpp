// Mbuild Tic Tac Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <cctype>
#include <limits>

#include "TacBoard.h"
#include "TerminalDisplay.h"

using namespace std;

void printInstructions()
{
	cout << "Welcome to Tic Tac Toe! " << endl << endl;
	cout << "How To Play: " << endl;
	cout << "Tic Tac Toe is a game played on a 3 x 3 board." << endl;
    cout << "The rows are labeled A, B, C." << endl;
	cout << "The columns are labeled 1, 2, 3." << endl;
	cout << "There are two players, one player will be assigned the letter 'X' and the other will be assigned 'O'." << endl;
	cout << "The player who gets the first move of the game will be random." << endl;
	cout << "Each player will alternate turns and get one move at a time." << endl;
	cout << "If a player enters an invalid spot / a spot already taken on the board, that player will be asked to re-enter their move to an available spot on the board." << endl;
	cout << "The objective of the game is to get 3 'X's or 3 'O's in a row either horizontally, vertically, or diagonally." << endl;
	cout << "If the board is filled and there is no sequence of 3 'X's or 3 'O's in a row as stated above, the game ends in a tie." << endl;
    cout << "Enter 'q' to quit at any time. " << endl << endl;
    cout << "Press Enter to continue:" << endl;
}

int main()
{
    
    srand(time(NULL)); // creating to make a "real" random first move
    TerminalDisplay term;
    term.saveCursorPos();

    bool playAgain = true;

    while (playAgain) 
    {
        term.clearScreen(TerminalDisplay::ERASE_CURSOR_TO_SCREEN_START, true);
        // This long string is our logo. 
        cout << "\033[30;107m\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;231m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;231m \033[38;5;100m(\033[38;5;136m(\033[38;5;142m(\033[38;5;142m(\033[38;5;136m(\033[38;5;136m#\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;100m#\033[38;5;136m(\033[38;5;136m(\033[38;5;142m(\033[38;5;142m(\033[38;5;142m/\033[38;5;178m/\033[38;5;142m(\033[38;5;142m(\033[38;5;142m(\033[38;5;136m(\033[38;5;136m#\033[38;5;231m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;100m#\033[38;5;136m(\033[38;5;136m(\033[38;5;142m(\033[38;5;142m(\033[38;5;178m(\033[38;5;178m/\033[38;5;142m(\033[38;5;142m(\033[38;5;142m(\033[38;5;136m(\033[38;5;136m#\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;100m(\033[38;5;136m(\033[38;5;136m(\033[38;5;142m(\033[38;5;142m(\033[38;5;142m(\033[38;5;178m/\033[38;5;142m(\033[38;5;142m(\033[38;5;136m(\033[38;5;136m(\033[38;5;136m#\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;094m#\033[38;5;130m#\033[38;5;136m(\033[38;5;136m(\033[38;5;136m(\033[38;5;136m(\033[38;5;136m(\033[38;5;136m#\033[38;5;130m#\033[38;5;094m#\033[38;5;095m(\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;124m#\033[38;5;160m#\033[38;5;124m#\033[38;5;124m%\033[38;5;124m#\033[38;5;124m#\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m#\033[38;5;124m%\033[38;5;124m#\033[38;5;210m*\033[38;5;124m%\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m#\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m#\033[38;5;124m%\033[38;5;124m#\033[38;5;124m#\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;088m%\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;181m,\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m#\033[38;5;124m#\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m#\033[38;5;124m%\033[38;5;124m#\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;088m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m#\033[38;5;124m%\033[38;5;124m%\033[38;5;124m#\033[38;5;124m#\033[38;5;088m&\033[38;5;124m#\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;124m%\033[38;5;124m%\033[38;5;124m#\033[38;5;124m%\033[38;5;088m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;088m%\033[38;5;124m%\033[38;5;124m#\033[38;5;124m%\033[38;5;088m%\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;255m \033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;088m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m#\033[38;5;124m#\033[38;5;124m#\033[38;5;124m%\033[38;5;124m#\033[38;5;052m&\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;124m%\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;142m/\033[38;5;142m(\033[38;5;142m(\033[38;5;136m#\033[38;5;094m#\033[38;5;015m \033[38;5;060m#\033[38;5;060m#\033[38;5;060m(\033[38;5;060m#\033[38;5;060m(\033[38;5;060m#\033[38;5;060m#\033[38;5;060m#\033[38;5;060m#\033[38;5;060m(\033[38;5;061m(\033[38;5;060m(\033[38;5;061m(\033[38;5;060m#\033[38;5;024m#\033[38;5;060m#\033[38;5;239m#\033[38;5;231m \033[38;5;094m%\033[38;5;136m#\033[38;5;142m(\033[38;5;142m(\033[38;5;136m(\033[38;5;136m(\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;142m(\033[38;5;136m#\033[38;5;015m \033[38;5;015m \033[38;5;142m(\033[38;5;003m#\033[38;5;058m%\033[38;5;017m&\033[38;5;017m&\033[38;5;023m%\033[38;5;023m%\033[38;5;023m%\033[38;5;023m%\033[38;5;023m%\033[38;5;023m%\033[38;5;023m%\033[38;5;023m%\033[38;5;017m&\033[38;5;017m&\033[38;5;017m&\033[38;5;017m&\033[38;5;236m&\033[38;5;234m&\033[38;5;234m&\033[38;5;015m \033[38;5;100m#\033[38;5;142m(\033[38;5;136m(\033[38;5;143m/\033[38;5;142m(\033[38;5;142m(\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;024m%\033[38;5;024m%\033[38;5;024m#\033[38;5;024m%\033[38;5;024m%\033[38;5;024m#\033[38;5;024m#\033[38;5;067m/\033[38;5;060m(\033[38;5;067m/\033[38;5;024m%\033[38;5;024m#\033[38;5;024m#\033[38;5;017m&\033[38;5;024m%\033[38;5;017m%\033[38;5;152m,\033[38;5;015m \033[38;5;255m \033[38;5;136m(\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;253m.\033[38;5;024m#\033[38;5;109m*\033[38;5;024m%\033[38;5;017m&\033[38;5;017m&\033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;024m%\033[38;5;017m&\033[38;5;017m&\033[38;5;023m%\033[38;5;024m#\033[38;5;024m#\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;103m*\033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;023m%\033[38;5;015m \033[38;5;024m#\033[38;5;024m#\033[38;5;025m#\033[38;5;024m#\033[38;5;025m#\033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;060m(\033[38;5;024m#\033[38;5;234m&\033[38;5;234m&\033[38;5;235m&\033[38;5;234m&\033[38;5;024m%\033[38;5;024m#\033[38;5;024m%\033[38;5;015m \033[38;5;024m#\033[38;5;024m#\033[38;5;235m&\033[38;5;235m&\033[38;5;234m&\033[38;5;234m&\033[38;5;024m#\033[38;5;024m#\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;060m#\033[38;5;023m%\033[38;5;024m%\033[38;5;024m%\033[38;5;024m%\033[38;5;024m%\033[38;5;024m%\033[38;5;024m#\033[38;5;024m#\033[38;5;015m \033[38;5;024m#\033[38;5;017m&\033[38;5;024m%\033[38;5;024m%\033[38;5;024m%\033[38;5;024m%\033[38;5;017m&\033[38;5;024m#\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;024m%\033[38;5;017m&\033[38;5;023m%\033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;015m \033[38;5;024m#\033[38;5;024m#\033[38;5;024m#\033[38;5;023m%\033[38;5;023m%\033[38;5;024m#\033[38;5;024m#\033[38;5;025m#\033[38;5;231m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m \033[38;5;015m\n\033[0m" << endl;

        cout << "              " << term.consoleFonts.beginBlink() << term.consoleFonts.beginBold() << "Master Builders Software" << term.consoleFonts.endBold() << term.consoleFonts.endBlink() << endl;

        cout << "Press Enter to continue" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        term.clearScreen(TerminalDisplay::ERASE_CURSOR_TO_SCREEN_START, true);
        term.restoreCursorPos();
        TacBoard TicTacToe;
        printInstructions();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        term.clearScreen(TerminalDisplay::ERASE_CURSOR_TO_SCREEN_START, true);
        term.restoreCursorPos();

        cout << "[Master Builders Tic Tac Toe]" << endl;
        TicTacToe.printBoard();
        while (TicTacToe.whichPlayerWon() == TacBoard::PLAYER_BLANK)
        {
            cout << "It's " << TicTacToe.getPlayerTurn() << "'s turn!" << endl;
            bool validSpace = false;
            bool validInput = false;
            string pos;
            while (validSpace != validInput || validInput == false)
            {
                cout << "Enter a position: ";
                getline(cin, pos);
                if (pos == "q")
                {
                    TicTacToe.quitProgram();
                }
                else
                {
                validSpace = TicTacToe.addSpace(pos, validInput);
                term.moveToPreviousLine();
                term.clearScreen(TerminalDisplay::ERASE_ENTIRE_LINE, true);
                }
               
            }
            TicTacToe.printBoard();
        }

        term.moveToPreviousLine();
        term.clearScreen(TerminalDisplay::ERASE_ENTIRE_LINE, true);
        cout << "Player won: " << TicTacToe.checkPlayerWin() << endl;

        TicTacToe.trackWinner();

        TicTacToe.restartGame();
    }
    return 0;
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