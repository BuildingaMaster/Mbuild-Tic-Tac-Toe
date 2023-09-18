#include "TerminalDisplay.h"

using namespace std;

void TerminalDisplay::saveCursorPos()
{
    cout << returnTerminalCode(ESC) << "7";
}
void TerminalDisplay::restoreCursorPos()
{
    cout << returnTerminalCode(ESC) << "8";
}

char TerminalDisplay::returnTerminalCode(TerminalDisplay::terminalCodes code)
{
    switch (code)
    {
        case BEL:
            return '\007';
        case BS:
            return '\010';
        case HT:
            return '\011';
        case LF:
            return '\012';
        case VT:
            return '\013';
        case FF:
            return '\014';
        case CR:
            return '\015';
        case ESC:
            return '\033';
        case DEL:
            return '\177';
    }
}

std::string TerminalDisplay::consoleFonts::beginBold()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[1m");
    return str;
}
std::string TerminalDisplay::consoleFonts::endBold()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[22m");
    return str;
}
std::string TerminalDisplay::consoleFonts::beginDim()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[2m");
    return str;
}
std::string TerminalDisplay::consoleFonts::endDim()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[22m");
    return str;
}
std::string TerminalDisplay::consoleFonts::beginItalic()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[3m");
    return str;
}
std::string TerminalDisplay::consoleFonts::endItalic()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[23m");
    return str;
}
std::string TerminalDisplay::consoleFonts::beginUnderline()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[4m");
    return str;
}
std::string TerminalDisplay::consoleFonts::endUnderline()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[24m");
    return str;
}
std::string TerminalDisplay::consoleFonts::beginBlink()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[5m");
    return str;
}
std::string TerminalDisplay::consoleFonts::endBlink()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[25m");
    return str;
}
std::string TerminalDisplay::consoleFonts::beginReverse()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[6m");
    return str;
}
std::string TerminalDisplay::consoleFonts::endReverse()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[26m");
    return str;
}
std::string TerminalDisplay::consoleFonts::beginHiddenText()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[7m");
    return str;
}
std::string TerminalDisplay::consoleFonts::endHiddenText()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[27m");
    return str;
}
std::string TerminalDisplay::consoleFonts::beginStrikeThrough()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[8m");
    return str;
}
std::string TerminalDisplay::consoleFonts::endStrikeThrough()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[28m");
    return str;
}

std::string TerminalDisplay::consoleColors::returnForegroundColor(ForegroundColors color)
{
    switch (color)
    {
        case FG_RESET:
            return "0";
        case FG_BLACK:
            return "30";
        case FG_RED:
            return "31";
        case FG_GREEN:
            return "32";
        case FG_YELLOW:
            return "33";
        case FG_BLUE:
            return "34";
        case FG_MAGENTA:
            return "35";
        case FG_CYAN:
            return "36";
        case FG_WHITE:
            return "37";
        case FG_CUSTOM:
            return "38";
        case FG_DEFAULT:
            return "39";
        case FG_BRIGHTBLACK:
            return "100";
        case FG_BRIGHTRED:
            return "101";
        case FG_BRIGHTGREEN:
            return "102";
        case FG_BRIGHTYELLOW:
            return "103";
        case FG_BRIGHTBLUE:
            return "104";
        case FG_BRIGHTMAGENTA:
            return "105";
        case FG_BRIGHTCYAN:
            return "106";
        case FG_BRIGHTWHITE:
            return "107";
    }
}
std::string TerminalDisplay::consoleColors::returnBackgroundColor(BackgroundColors color)
{
    switch (color)
    {
        case BG_RESET:
            return "0";
        case BG_BLACK:
            return "40";
        case BG_RED:
            return "41";
        case BG_GREEN:
            return "42";
        case BG_YELLOW:
            return "43";
        case BG_BLUE:
            return "44";
        case BG_MAGENTA:
            return "45";
        case BG_CYAN:
            return "46";
        case BG_WHITE:
            return "47";
        case BG_CUSTOM:
            return "48";
        case BG_DEFAULT:
            return "49";
        case BG_BRIGHTBLACK:
            return "100";
        case BG_BRIGHTRED:
            return "101";
        case BG_BRIGHTGREEN:
            return "102";
        case BG_BRIGHTYELLOW:
            return "103";
        case BG_BRIGHTBLUE:
            return "104";
        case BG_BRIGHTMAGENTA:
            return "105";
        case BG_BRIGHTCYAN:
            return "106";
        case BG_BRIGHTWHITE:
            return "107";
    }
}

void TerminalDisplay::consoleColors::setFGTextColor(ForegroundColors color)
{
    if (color == FG_CUSTOM)
    {
        throw std::invalid_argument("setFGTextColor cannot be BG_CUSTOM. Enter an integer from 0-255 instead.");
    }
    std::string str(1,returnTerminalCode(ESC));
    str.append("["+returnForegroundColor(color)+"m");
    cout << str;
}
void TerminalDisplay::consoleColors::setBGTextColor(BackgroundColors color)
{
    if (color == BG_CUSTOM)
    {
        throw std::invalid_argument("setFGTextColor cannot be BG_CUSTOM. Enter an integer from 0-255 instead.");
    }
    std::string str(1,returnTerminalCode(ESC));
    str.append("["+returnBackgroundColor(color)+"m");
    cout << str;
}
void TerminalDisplay::consoleColors::setFGTextColor(int color)
{
    if (color < 0 || color > 255)
    {
        throw std::invalid_argument("Invalid range. Must be between 0-255 inclusive.");
    }
    std::string str(1,returnTerminalCode(ESC));
    str.append("["+returnForegroundColor(FG_CUSTOM)+";5;"+to_string(color)+"m");
    cout << str;
}
void TerminalDisplay::consoleColors::setBGTextColor(int color)
{
    if (color < 0 || color > 255)
    {
        throw std::invalid_argument("Invalid range. Must be between 0-255 inclusive.");
    }
    std::string str(1,returnTerminalCode(ESC));
    str.append("["+returnBackgroundColor(BG_CUSTOM)+";5;"+to_string(color)+"m");
    cout << str;
}

void TerminalDisplay::resetAllStyles()
{
    std::string str(1,returnTerminalCode(ESC));
    str.append("[0m");
    cout << str;
}


TerminalDisplay::~TerminalDisplay()
{
    resetAllStyles();
}