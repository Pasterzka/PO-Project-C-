#include "Owca.h"

Owca::Owca(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Zwierze(swiat)
{
	Organizm::inicjatywa = 4;
	Organizm::sila = 4;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

Owca::Owca(int inicjatywa, int sila, int pozycjaX, int pozycjaY, int wiek, Swiat& swiat)
	:Zwierze(swiat)
{
	Organizm::inicjatywa = inicjatywa;
	Organizm::sila = sila;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
	Organizm::wiek = wiek;
}

void Owca::Akcja()
{
	Zwierze::Akcja();
}

void Owca::Kolizja(Organizm* organizmy)
{
}

void Owca::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "O";
}

Owca::~Owca()
{
}
