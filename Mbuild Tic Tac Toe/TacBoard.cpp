#include <iostream>
#include "TacBoard.h"

using namespace std;

TacBoard::TacBoard()
{
    hasPrintedBefore = false;
    winner = PLAYER_BLANK;
    turnCount = 0;
    firstMove();
}
void TacBoard::firstMove()
{
	int randNum = rand() % 2;
	
	if (randNum == 1)
	{
		Turn = PLAYER_X;
	}
	else
	{
		Turn = PLAYER_O;
	}
}
void TacBoard::printBoard()
{
    // If this is the first time the board is printed:
    // Save where it is to overwrite it later.
    if (hasPrintedBefore == false)
    {
        term.saveCursorPos();
        hasPrintedBefore = true;
    }
    term.restoreCursorPos();
    checkPlayerWin();
    for (char i = '1'; i <= '3'; i++) // Traverse by rows
    {
        for (int tileCount = 0; tileCount < 5; tileCount++)
        {
            // If the player won in this square, color it green.
            if (BoardGUI.win_board['A'][i] == PLAYER_WIN)
            {
                term.consoleColors.setBGTextColor(118);
            }
            cout << BoardGUI.playerIDtoDisplayID[BoardGUI.board_status['A'][i]][tileCount];
            term.consoleColors.setBGTextColor(TerminalDisplay::consoleColors::BG_DEFAULT);
            if (tileCount == 2 && BoardGUI.board_status['A'][i] == PLAYER_BLANK)
            {
                term.consoleCursorControls.moveCursorNColumns(-7);
                cout << term.consoleFonts.beginDim() << "A " << i << term.consoleFonts.endDim();
                term.consoleCursorControls.moveCursorNColumns(4);
            }
            cout << "|";
            if (BoardGUI.win_board['B'][i] == PLAYER_WIN)
            {
                term.consoleColors.setBGTextColor(118);
            }
            cout << BoardGUI.playerIDtoDisplayID[BoardGUI.board_status['B'][i]][tileCount];
            term.consoleColors.setBGTextColor(TerminalDisplay::consoleColors::BG_DEFAULT);
            if (tileCount == 2 && BoardGUI.board_status['B'][i] == PLAYER_BLANK)
            {
                
                term.consoleCursorControls.moveCursorNColumns(-7);
                cout << term.consoleFonts.beginDim() << "B " << i << term.consoleFonts.endDim();
                term.consoleCursorControls.moveCursorNColumns(4);
            }
            cout << "|";
            if (BoardGUI.win_board['C'][i] == PLAYER_WIN)
            {
                term.consoleColors.setBGTextColor(118);
            }
            cout << BoardGUI.playerIDtoDisplayID[BoardGUI.board_status['C'][i]][tileCount];
            term.consoleColors.setBGTextColor(TerminalDisplay::consoleColors::BG_DEFAULT);
            if (tileCount == 2 && BoardGUI.board_status['C'][i] == PLAYER_BLANK)
            {
                
                term.consoleCursorControls.moveCursorNColumns(-7);
                cout << term.consoleFonts.beginDim() << "C " << i << term.consoleFonts.endDim();
                term.consoleCursorControls.moveCursorNColumns(4);
            }
            cout << endl;
        }
        if (i <= '2') // We only need to print this twice
        {
            cout <<"-----------+-----------+-----------" << endl;
        }
    }
    cout << endl;
}

TacBoard::playerID TacBoard::whichPlayerWon()
{
    return winner;
}

string TacBoard::getPlayerTurn()
{
    switch (Turn)
    {
        case PLAYER_X:
            {
                return "Player X";
            }
        case PLAYER_O:
            {
                return "Player O";
            }
        default:
            {
                return "";
            }
    }
   
}

/// @brief  Determines who won the game.
/// @return PLAYER_BLANK for nobody, PLAYER_X, or PLAYER_Y
TacBoard::playerID TacBoard::checkPlayerWin()
{
    if (winner != PLAYER_BLANK)
    {
        return winner;
    }
    
    for (char i = 'A'; i <= 'C'; i++)
    {
        if ((BoardGUI.board_status[i]['1'] == BoardGUI.board_status[i]['2'] && BoardGUI.board_status[i]['2'] == BoardGUI.board_status[i]['3']) && BoardGUI.board_status[i]['2'] != PLAYER_BLANK )
        {
            BoardGUI.win_board[i]['1'] = BoardGUI.win_board[i]['2'] = BoardGUI.win_board[i]['3'] = PLAYER_WIN;
            winner = BoardGUI.board_status[i]['1'];
        }
    }
    for (char i = '1'; i <= '3'; i++)
    {
        if ((BoardGUI.board_status['A'][i] == BoardGUI.board_status['B'][i] && BoardGUI.board_status['B'][i]  == BoardGUI.board_status['C'][i]) && BoardGUI.board_status['B'][i] != PLAYER_BLANK)
        {
            BoardGUI.win_board['A'][i] = BoardGUI.win_board['B'][i] = BoardGUI.win_board['C'][i] = PLAYER_WIN;
            winner = BoardGUI.board_status['A'][i];
        }
    }

    if ((BoardGUI.board_status['A']['1'] == BoardGUI.board_status['B']['2'] && BoardGUI.board_status['B']['2'] == BoardGUI.board_status['C']['3']) && BoardGUI.board_status['B']['2'] != PLAYER_BLANK)
    {
        BoardGUI.win_board['A']['1'] = BoardGUI.win_board['B']['2'] = BoardGUI.win_board['C']['3'] = PLAYER_WIN;
        winner = BoardGUI.win_board['B']['2'];
    } 
    if ((BoardGUI.board_status['C']['1'] == BoardGUI.board_status['B']['2'] && BoardGUI.board_status['B']['2'] == BoardGUI.board_status['A']['3']) && BoardGUI.board_status['B']['2'] != PLAYER_BLANK)
    {
        BoardGUI.win_board['C']['1'] = BoardGUI.win_board['B']['2'] = BoardGUI.win_board['A']['3'] = PLAYER_WIN;
        winner = BoardGUI.win_board['B']['2'];
    }
    if (turnCount >= 9 && winner == PLAYER_BLANK)
    {
        winner = PLAYER_INVALID;
    }
    return winner;
}
/// @brief Get the win type. (Unused currently)
/// @return  The win type, like if a player won by a row.s
TacBoard::winType TacBoard::getWinType()
{
    for (char i = 'A'; i <= 'C'; i++) //Col
    {
        if ((BoardGUI.board_status[i]['1'] == BoardGUI.board_status[i]['2'] && BoardGUI.board_status[i]['2'] == BoardGUI.board_status[i]['3']) && BoardGUI.board_status[i]['2'] != PLAYER_BLANK )
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
    for (char i = '1'; i <= '3'; i++) //Row
    {
        if ((BoardGUI.board_status['A'][i] == BoardGUI.board_status['B'][i] && BoardGUI.board_status['B'][i]  == BoardGUI.board_status['C'][i]) && BoardGUI.board_status['B'][i] != PLAYER_BLANK)
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
    if ((BoardGUI.board_status['A']['1'] == BoardGUI.board_status['B']['2'] && BoardGUI.board_status['B']['2'] == BoardGUI.board_status['C']['3']) && BoardGUI.board_status['B']['2'] != PLAYER_BLANK)
    {
        return DIAG_LTR;
    } 
    if ((BoardGUI.board_status['C']['1'] == BoardGUI.board_status['B']['2'] && BoardGUI.board_status['B']['2'] == BoardGUI.board_status['A']['3']) && BoardGUI.board_status['B']['2'] != PLAYER_BLANK)
    {
        return DIAG_RTL;
    }
    return NONE;
}

TacBoard::playerID TacBoard::checkSpace(char Column, char Row)
{
    if (Column >= 'A' && Column <= 'C' && Row >= '1' && Row <= '3')
    {
        return BoardGUI.board_status[Column][Row];
    }
    return PLAYER_INVALID;
    
}
// Returns what letter currently occupies a specific space on the board ( row x column )
// Returns '\0' if the space is empty

void TacBoard::nextTurn()
{
    turnCount+=1;
	if (Turn == PLAYER_O)
	{
		Turn = PLAYER_X;
        return;
	}

	Turn = PLAYER_O;
	return;
}
// Called after adding a space, switches to the next turn

bool TacBoard::addSpace(std::string input, bool &isGoodInput)
{
    isGoodInput = true;
    if (input.size() != 2)
    {
        isGoodInput = false;
        return false;
    }
    char Column = input[0];
    char Row = input[1];
    if (Column >= 'a' && Column <= 'c')
    {
        Column -= 32;
    }

    if ((Column < 'A' || Column > 'C') || (Row < '1' || Row > '3'))
    {
        isGoodInput = false;
        return false;
    }

    playerID ID = checkSpace(Column, Row);
	if (ID == PLAYER_BLANK || ID == PLAYER_INVALID)
	{
		BoardGUI.board_status[Column][Row] = Turn;
		nextTurn();
        return true;
	}
    return false; 
}

void TacBoard::boardReset()
{
    for (char col = 'A'; col <= 'C'; col++)
    {
        for (char row = '1'; row <= '3'; row++)
        {
            BoardGUI.board_status[col][row] = BoardGUI.win_board[col][row] = PLAYER_BLANK;
        }
    }
    winner = PLAYER_BLANK;
    turnCount = 0;
    firstMove();
}

//Game restarts
void TacBoard::restartGame() 
{
    char choice;
    cout << "Do you want to play another game? (Y/N)";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        boardReset();
    }
    else
    {
        quitProgram();
    }
    cout << "The game has been restarted." << endl;
}


void TacBoard::quitProgram()
{
    cout << " Exiting the program. " << endl;
    exit(0);

}

// trackWinner
void TacBoard::trackWinner()
{
    if (winner == PLAYER_X)
    {
        player_x_wins+= 1;
        cout << "Player X has " << player_o_wins << " wins" << endl;
    }
    else if (winner == PLAYER_O)
    {
        player_o_wins+= 1;
        cout << "Player O has " << player_x_wins << " wins" << endl;
    }
}
