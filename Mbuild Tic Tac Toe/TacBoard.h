#pragma once
#include <vector>
#include <string>
#include <map>

#include "TerminalDisplay.h"

class TacBoard
{
private:
	TerminalDisplay term;
	bool hasPrintedBefore;
public:
	enum playerID
	{
		PLAYER_WIN = 2,
		PLAYER_X = 1,
		PLAYER_O = 0,
		PLAYER_BLANK = -1,
		PLAYER_INVALID = -2
	};
	enum winType
	{
		NONE,
		ROW_1,
		ROW_2,
		ROW_3,
		COL_A,
		COL_B,
		COL_C,
		DIAG_LTR,
		DIAG_RTL
	};
private:
	playerID winner;
public:
	void printBoard();
	playerID whichPlayerWon();
	winType getWinType();
	
	playerID checkPlayerWin();

	void boardReset();

	bool addSpace(std::string, bool &);
	playerID checkSpace(char, char);

	playerID Turn = PLAYER_BLANK;
	void nextTurn();
	std::string getPlayerTurn();

	class BoardGUI
	{
	public:
		/// @brief The area of play. Needs to be reset after a win. 
		std::map<char, std::map<char, playerID>> board_status = {
			{'A', {{'1', PLAYER_BLANK}, {'2', PLAYER_BLANK}, {'3', PLAYER_BLANK}}},
			{'B', {{'1', PLAYER_BLANK}, {'2', PLAYER_BLANK}, {'3', PLAYER_BLANK}}},
			{'C', {{'1', PLAYER_BLANK}, {'2', PLAYER_BLANK}, {'3', PLAYER_BLANK}}}};
		
		/// @brief Formatting purposes. Checks what boxes need to be colored. Needs to be reset after a win. 
		std::map<char, std::map<char, playerID>> win_board = {
			{'A', {{'1', PLAYER_BLANK}, {'2', PLAYER_BLANK}, {'3', PLAYER_BLANK}}},
			{'B', {{'1', PLAYER_BLANK}, {'2', PLAYER_BLANK}, {'3', PLAYER_BLANK}}},
			{'C', {{'1', PLAYER_BLANK}, {'2', PLAYER_BLANK}, {'3', PLAYER_BLANK}}}};
		
		/// @brief A vector that contains the playerID which corresponds to a design of X, O or blank.
		std::map<playerID, std::vector<std::string>> playerIDtoDisplayID =
			{{PLAYER_X, std::vector<std::string>{"   X   X   ", "    X X    ", "     X     ", "    X X    ", "   X   X   "}}, {PLAYER_O, std::vector<std::string>{"    OOO    ", "   OO OO   ", "   O   O   ", "   OO OO   ", "    OOO    "}}, {PLAYER_BLANK, std::vector<std::string>{"           ", "           ", "           ", "           ", "           "}}};
		

	} BoardGUI;

	TacBoard();
};