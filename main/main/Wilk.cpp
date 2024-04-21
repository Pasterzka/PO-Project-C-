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

Wilk::Wilk(int inicjatywa, int sila, int pozycjaX, int pozycjaY, int wiek, Swiat& swiat)
	:Zwierze(swiat)
{
	Organizm::inicjatywa = inicjatywa;
	Organizm::sila = sila;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
	Organizm::wiek = wiek;
}

void Wilk::Akcja()
{
	Zwierze::Akcja();
}

void Wilk::Kolizja(Organizm* organizmy)
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
