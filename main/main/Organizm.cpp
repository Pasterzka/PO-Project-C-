#include "Organizm.h"

Organizm::Organizm(Swiat& swiat)
	:sila(0), inicjatywa(0), pozycjaX(0), pozycjaY(0), swiat(swiat)
{
}

int Organizm::GetPozycjaX() const
{
	return pozycjaX;
}

int Organizm::GetPozycjaY() const
{
	return pozycjaY;
}

void Organizm::Wypisz()
{
}

