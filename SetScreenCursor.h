#include <iostream>
#include <windows.h> 

using namespace std;

void SetScreenCursor(int SSCx,int SSCy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {SSCx, SSCy};
	SetConsoleCursorPosition(hConsole, coord);
}
