#include "Guarana.h"

Guarana::Guarana(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::pozycjaY = pozycjaY;
	Organizm::pozycjaX = pozycjaX;
	Organizm::swiat = swiat;
}

Guarana::Guarana(int inicjatywa, int sila, int pozycjaX, int pozycjaY, int wiek, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::sila = sila;
	Organizm::inicjatywa = inicjatywa;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
	Organizm::wiek = wiek;
}

void Guarana::Akcja()
{
	Roslina::Akcja();
}

void Guarana::Kolizja(Organizm* organizmy)
{
	organizmy->setSila(3);
}

void Guarana::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "G";
}

Guarana::~Guarana()
{
}
