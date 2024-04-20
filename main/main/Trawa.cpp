#include "Trawa.h"

Trawa::Trawa(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

void Trawa::Kolizja()
{
}

void Trawa::Akcja()
{
	Roslina::Akcja();
}

void Trawa::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "T";
}

Trawa::~Trawa()
{
}
