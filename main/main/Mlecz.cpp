#include "Mlecz.h"

Mlecz::Mlecz(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

Mlecz::Mlecz(int inicjatywa, int sila, int pozycjaX, int pozycjaY, int wiek, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::sila = sila;
	Organizm::inicjatywa = inicjatywa;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
	Organizm::wiek = wiek;
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
