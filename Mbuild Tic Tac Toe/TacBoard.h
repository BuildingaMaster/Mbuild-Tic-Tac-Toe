#pragma once
#include <vector>
#include <string>
#include <map>

#include "TerminalDisplay.h"

class TacBoard
{
private:
	TerminalDisplay term;
public:
	enum playerID
	{
		PLAYER_WIN = 2,
		PLAYER_X = 1,
		PLAYER_O = 0,
		PLAYER_BLANK = -1
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

	bool hasPrintedBefore;
	void printBoard();
	winType getWinType();
	
	playerID checkPlayerWin();

	bool addSpace(char, char);
	playerID checkSpace(char, char);

	playerID Turn = PLAYER_BLANK;
	void nextTurn();

	class BoardGUI
	{
	public:
		std::map<char, std::map<char, playerID>> board_status = {
			{'A', {{'1', PLAYER_BLANK}, {'2', PLAYER_BLANK}, {'3', PLAYER_BLANK}}},
			{'B', {{'1', PLAYER_BLANK}, {'2', PLAYER_BLANK}, {'3', PLAYER_BLANK}}},
			{'C', {{'1', PLAYER_BLANK}, {'2', PLAYER_BLANK}, {'3', PLAYER_BLANK}}}};
		
		std::map<char, std::map<char, playerID>> win_board = {
			{'A', {{'1', PLAYER_BLANK}, {'2', PLAYER_BLANK}, {'3', PLAYER_BLANK}}},
			{'B', {{'1', PLAYER_BLANK}, {'2', PLAYER_BLANK}, {'3', PLAYER_BLANK}}},
			{'C', {{'1', PLAYER_BLANK}, {'2', PLAYER_BLANK}, {'3', PLAYER_BLANK}}}};

		std::map<playerID, std::vector<std::string>> playerIDtoDisplayID =
			{{PLAYER_X, std::vector<std::string>{"   X   X   ", "    X X    ", "     X     ", "    X X    ", "   X   X   "}}, {PLAYER_O, std::vector<std::string>{"    OOO    ", "   OO OO   ", "   O   O   ", "   OO OO   ", "    OOO    "}}, {PLAYER_BLANK, std::vector<std::string>{"           ", "           ", "           ", "           ", "           "}}};
	} BoardGUI;

	TacBoard();
};