#ifndef MAINHEADER_H
#define MAINHEADER_H

//#define DEBUG

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

#ifdef __MINGW32__
#include <windows.h>
#include <conio.h>
#include <math.h>
#define CLEAR_SCREEN "cls"
//#pragma execution_character_set( "utf-8" )
#define SET_CONSOLE

#else
#include "code_linux.h"
#define CLEAR_SCREEN "clear"
#endif

inline void CODEModify (const char stringfPrint[]) {
	#ifdef SET_CONSOLE
    wchar_t wstr[128];
    MultiByteToWideChar( CP_UTF8, 0, stringfPrint, 128, wstr, 128 );
    wcout << wstr;
    #else
    cout << stringfPrint;
	#endif // SET_CONSOLE
}


//ЦВЕТА ТЕКСТА
#define	BLACK "\033[1;30m"
#define	BLUE "\033[1;34m"
#define	GREEN "\033[1;32m"
#define	RED "\033[1;31m"
#define	YELLOW "\033[1;33m"
#define	WHITE "\033[1;37m"


#define FILE_RW "PhoneBook.db"
#define FILE_W "PhoneBook_.db"

#endif //MAINHEADER_H
