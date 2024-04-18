#include "Czlowiek.h"
#include "Definicje.h"

Czlowiek::Czlowiek(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Zwierze(swiat)
{
	Organizm::sila = 5;
	Organizm::inicjatywa = 4;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
	this->zdolnosc = 5;
}

void Czlowiek::Akcja()
{
	int kierunek;
	Gotoxy(1, swiat.GetWysokosc() + 7);
	std::cout << "Wubierz kierunek, w krorym sie poruszysz: ";
	std::cin >> kierunek;
	
	switch (kierunek)
	{
	case 8:
		if (pozycjaY != 1)
		{
			Organizm::pozycjaY--;
		}
		break;
	case 6:
		if (pozycjaX != swiat.GetSzerokosc())
		{
			Organizm::pozycjaX++;
		}
		break;
	case 2:
		if (pozycjaY != swiat.GetWysokosc())
		{
			Organizm::pozycjaY++;
		}
		break;
	case 4:
		if (pozycjaX != 1)
		{
			Organizm::pozycjaX--;
		}
		break;
	case 5:
		if (zdolnosc==5)
		{
			zdolnosc = 0;
			std::cout << std::endl << "zdolnosc";
		}
		else {
			std::cout << std::endl << "zdolnosc sie laduje";
		}
	default:
		break;
	}
	if (zdolnosc!=5)
	{
		zdolnosc++;
	}
}

void Czlowiek::Kolizja()
{
}

void Czlowiek::Wypisz()
{
	Gotoxy(Organizm::pozycjaX+1, Organizm::pozycjaY+3);
	std::cout << 'C';
}

Czlowiek::~Czlowiek()
{
}
