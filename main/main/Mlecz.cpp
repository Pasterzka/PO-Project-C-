#include "Mlecz.h"

Mlecz::Mlecz(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

void Mlecz::Akcja()
{
	for (int i = 0; i < 3; i++)
	{
		Roslina::Akcja();
	}
}

void Mlecz::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "M";
}

void Mlecz::Kolizja(Organizm* organizmy)
{
}

Mlecz::~Mlecz()
{
}
