#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <map>
class TerminalDisplay
{
private:
    enum terminalCodes
    {
        BEL = 7,
        BS = 8,
        HT = 9,
        LF = 10,
        VT = 11,
        FF = 12,
        CR = 13,
        ESC = 27,
        DEL = 127
    };
    static char returnTerminalCode(terminalCodes);
public:
    enum screenEraseModes
    {
        ERASE_CURSOR_TO_SCREEN_END,
        ERASE_CURSOR_TO_SCREEN_START,
        ERASE_ENTIRE_SCREEN,
        ERASE_SAVED_LINES,
        ERASE_CURSOR_TO_LINE_END,
        ERASE_LINE_START_TO_CURSOR,
        ERASE_ENTIRE_LINE
    };
private:
    static std::string returnScreenEraseMode(screenEraseModes);
public:
    ~TerminalDisplay();
    void saveCursorPos();
    void restoreCursorPos();
    void moveToPreviousLine();
    void moveToNextLine();
    void clearScreen(screenEraseModes,bool);
    void resetAllStyles();
    class consoleCursorControls
    {
        public:
            void moveToOrigin();
            void moveToPosition(int, int);
            void moveToLine(int, bool);
            void moveToColumn(int, bool);
            void moveCursorNColumns(int);

    } consoleCursorControls;
    class consoleFonts
    {
    public:
        std::string beginBold();
        std::string endBold();
        std::string beginDim();
        std::string endDim();
        std::string beginItalic();
        std::string endItalic();
        std::string beginUnderline();
        std::string endUnderline();
        std::string beginBlink();
        std::string endBlink();
        std::string beginReverse();
        std::string endReverse();
        std::string beginHiddenText();
        std::string endHiddenText();
        std::string beginStrikeThrough();
        std::string endStrikeThrough();

    } consoleFonts;
    class consoleColors
    {
    public:
        enum ForegroundColors
        {
            FG_RESET = 0,
            FG_BLACK = 30,
            FG_RED = 31,
            FG_GREEN = 32,
            FG_YELLOW = 33,
            FG_BLUE = 34,
            FG_MAGENTA = 35,
            FG_CYAN = 36,
            FG_WHITE = 37,
            FG_CUSTOM = 38,
            FG_DEFAULT = 39,
            FG_BRIGHTBLACK= 90,
            FG_BRIGHTRED = 91,
            FG_BRIGHTGREEN = 92,
            FG_BRIGHTYELLOW = 93,
            FG_BRIGHTBLUE = 94,
            FG_BRIGHTMAGENTA = 95,
            FG_BRIGHTCYAN = 96,
            FG_BRIGHTWHITE = 97
        };
        enum BackgroundColors
        {
            BG_RESET = 0,
            BG_BLACK = 40,
            BG_RED = 41,
            BG_GREEN = 42,
            BG_YELLOW = 43,
            BG_BLUE = 44,
            BG_MAGENTA = 45,
            BG_CYAN = 46,
            BG_WHITE = 47,
            BG_CUSTOM = 48,
            BG_DEFAULT = 49,
            BG_BRIGHTBLACK = 100,
            BG_BRIGHTRED = 101,
            BG_BRIGHTGREEN = 102,
            BG_BRIGHTYELLOW = 103,
            BG_BRIGHTBLUE = 104,
            BG_BRIGHTMAGENTA = 105,
            BG_BRIGHTCYAN = 106,
            BG_BRIGHTWHITE = 107
        };
        enum Type
        {
            FG,
            BG
        };
    private:
        static std::string returnForegroundColor(ForegroundColors);
        static std::string returnBackgroundColor(BackgroundColors);
    public:
        void setFGTextColor(ForegroundColors);
        void setFGTextColor(int);
        void setBGTextColor(BackgroundColors);
        void setBGTextColor(int);
    } consoleColors;
    
};
