#include <iostream>
#include "TacBoard.h"

using namespace std;

TacBoard::TacBoard()
{
    hasPrintedBefore = false;
}

void TacBoard::printBoard()
{
    if (hasPrintedBefore == false)
    {
        term.saveCursorPos();
        hasPrintedBefore = true;
    }
    term.restoreCursorPos();
    checkPlayerWin();
    for (char i = '1'; i < '4'; i++)
    {

        for (int tileCount = 0; tileCount < 5; tileCount++)
        {
            if (BoardGUI.win_board['A'][i] == PLAYER_WIN)
            {
                term.consoleColors.setBGTextColor(118);
            }
            cout << BoardGUI.playerIDtoDisplayID[BoardGUI.board_status['A'][i]][tileCount];
            term.consoleColors.setBGTextColor(TerminalDisplay::consoleColors::BG_DEFAULT);
            cout << "|";
            if (BoardGUI.win_board['B'][i] == PLAYER_WIN)
            {
                term.consoleColors.setBGTextColor(118);
            }
            cout << BoardGUI.playerIDtoDisplayID[BoardGUI.board_status['B'][i]][tileCount];
            term.consoleColors.setBGTextColor(TerminalDisplay::consoleColors::BG_DEFAULT);
            cout << "|";
            if (BoardGUI.win_board['C'][i] == PLAYER_WIN)
            {
                term.consoleColors.setBGTextColor(118);
            }
            cout << BoardGUI.playerIDtoDisplayID[BoardGUI.board_status['C'][i]][tileCount];
            term.consoleColors.setBGTextColor(TerminalDisplay::consoleColors::BG_DEFAULT);
            cout << endl;
        }
        if (i <= '2')
        {
            cout <<"-----------+-----------+-----------" << endl;
        }
    }
    cout << endl;
}

TacBoard::playerID TacBoard::checkPlayerWin()
{
    for (char i = 'A'; i < 'D'; i++)
    {
        if ((BoardGUI.board_status[i]['1'] == BoardGUI.board_status[i]['2'] == BoardGUI.board_status[i]['3']) && BoardGUI.board_status[i]['2'] != PLAYER_BLANK )
        {
            BoardGUI.win_board[i]['1'] = BoardGUI.win_board[i]['2'] = BoardGUI.win_board[i]['3'] = PLAYER_WIN;
            return BoardGUI.board_status[i]['1'];
        }
    }
    for (char i = '1'; i < '4'; i++)
    {
        if ((BoardGUI.board_status['A'][i] == BoardGUI.board_status['B'][i] == BoardGUI.board_status['C'][i]) && BoardGUI.board_status['B'][i] != PLAYER_BLANK)
        {
            BoardGUI.win_board['A'][i] = BoardGUI.win_board['B'][i] = BoardGUI.win_board['C'][i] = PLAYER_WIN;
            return BoardGUI.board_status['A'][i];
        }
    }

    if ((BoardGUI.board_status['A']['1'] == BoardGUI.board_status['B']['2'] == BoardGUI.board_status['C']['3']) && BoardGUI.board_status['B']['2'] != PLAYER_BLANK)
    {
        BoardGUI.win_board['A']['1'] = BoardGUI.win_board['B']['2'] = BoardGUI.win_board['C']['3'] = PLAYER_WIN;
        return BoardGUI.win_board['B']['2'];
    } 
    if ((BoardGUI.board_status['C']['1'] == BoardGUI.board_status['B']['2'] == BoardGUI.board_status['A']['3']) && BoardGUI.board_status['B']['2'] != PLAYER_BLANK)
    {
        BoardGUI.win_board['C']['1'] = BoardGUI.win_board['B']['2'] = BoardGUI.win_board['A']['3'] = PLAYER_WIN;
        return BoardGUI.win_board['B']['2'];
    }
    return PLAYER_BLANK;
}

TacBoard::winType TacBoard::getWinType()
{
    for (char i = 'A'; i < 'D'; i++) //Col
    {
        if ((BoardGUI.board_status[i]['1'] == BoardGUI.board_status[i]['2'] == BoardGUI.board_status[i]['3']) && BoardGUI.board_status[i]['2'] != PLAYER_BLANK )
        {
            switch (i)
            {
                case 'A':
                    return COL_A;
                case 'B':
                    return COL_B;
                case 'C':
                    return COL_C;                
            };
        }
    }
    for (char i = '1'; i < '4'; i++) //Row
    {
        if ((BoardGUI.board_status['A'][i] == BoardGUI.board_status['B'][i] == BoardGUI.board_status['C'][i]) && BoardGUI.board_status['B'][i] != PLAYER_BLANK)
        {
            switch (i)
            {
                case '1':
                    return ROW_1;
                case '2':
                    return ROW_2;
                case '3':
                    return ROW_3;                
            };
        }
    }
    if ((BoardGUI.board_status['A']['1'] == BoardGUI.board_status['B']['2'] == BoardGUI.board_status['C']['3']) && BoardGUI.board_status['B']['2'] != PLAYER_BLANK)
    {
        return DIAG_LTR;
    } 
    if ((BoardGUI.board_status['C']['1'] == BoardGUI.board_status['B']['2'] == BoardGUI.board_status['A']['3']) && BoardGUI.board_status['B']['2'] != PLAYER_BLANK)
    {
        return DIAG_RTL;
    }
    return NONE;
}

TacBoard::playerID TacBoard::checkSpace(char Row, char Column)
{
    return BoardGUI.board_status[Row][Column];
}
// Returns what letter currently occupies a specific space on the board ( row x column )
// Returns '\0' if the space is empty

void TacBoard::nextTurn()
{
	if (Turn == PLAYER_O)
	{
		Turn = PLAYER_O;
        return;
	}

	Turn = PLAYER_X;
	return;
}
// Called after adding a space, switches to the next turn

bool TacBoard::addSpace(char Row, char Column)
{
	if (checkSpace(Row, Column) != PLAYER_BLANK)
	{
		BoardGUI.board_status[Row][Column] = Turn;
		nextTurn();
        return true;
	}
    return false; 
}
