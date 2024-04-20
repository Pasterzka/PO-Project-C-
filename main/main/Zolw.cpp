#include "Zolw.h"

Zolw::Zolw(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Zwierze(swiat)
{
	Organizm::inicjatywa = 1;
	Organizm::sila = 2;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

void Zolw::Akcja()
{
	if (Szansa())
	{
		Zwierze::Akcja();
	}
}

void Zolw::Kolizja(Organizm* organizmy)
{
}

void Zolw::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "Z";
}

bool Zolw::Szansa()
{
	int los = rand() % 100 + 1;
	if (los>20)
	{
		return false;
	}
	else {
		return true;
	}
}

Zolw::~Zolw()
{
}
