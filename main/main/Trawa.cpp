#include "Trawa.h"

Trawa::Trawa(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

Trawa::Trawa(int inicjatywa, int sila, int pozycjaX, int pozycjaY, int wiek, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::sila = sila;
	Organizm::inicjatywa = inicjatywa;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
	Organizm::wiek = wiek;
}

void Trawa::Kolizja(Organizm* organizmy)
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
