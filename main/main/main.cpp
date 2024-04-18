#include <iostream>
#include <conio.h>

#include "Swiat.h"
#include "Czlowiek.h"

int main()
{
	std::vector<Organizm*> organizmy;

	Swiat swiat( 5, 5, &organizmy);

	organizmy.push_back(new Czlowiek(1, 1, swiat));


	do
	{
		system("cls");
		swiat.Wypisz();
		swiat.NastępnaTura();

		_getch();

		system("cls");
		swiat.Wypisz();

		_getch();
	} while (true);



	return 0;
}
