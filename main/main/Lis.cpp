#include "Lis.h"

Lis::Lis(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Zwierze(swiat)
{
	Organizm::inicjatywa = 7;
	Organizm::sila = 3;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

void Lis::Akcja()
{
	Zwierze::Akcja();
}

void Lis::Kolizja()
{
}

void Lis::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "L";
}

Lis::~Lis()
{
}
