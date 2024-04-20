#include "Wilk.h"

Wilk::Wilk(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Zwierze(swiat)
{
	Organizm::inicjatywa = 4;
	Organizm::sila = 9;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

void Wilk::Akcja()
{
	Zwierze::Akcja();
}

void Wilk::Kolizja()
{
}

void Wilk::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "W";
}

Wilk::~Wilk()
{
}
