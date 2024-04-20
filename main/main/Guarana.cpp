#include "Guarana.h"

Guarana::Guarana(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::pozycjaY = pozycjaY;
	Organizm::pozycjaX = pozycjaX;
	Organizm::swiat = swiat;
}

void Guarana::Akcja()
{
	Roslina::Akcja();
}

void Guarana::Kolizja()
{
}

void Guarana::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "G";
}

Guarana::~Guarana()
{
}
