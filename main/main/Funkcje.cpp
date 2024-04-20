#include "Funkcje.h"
#include <Windows.h>
#include "Organizm.h"

void Gotoxy(unsigned x, unsigned y)
{
	COORD coord = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetTextColour(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
