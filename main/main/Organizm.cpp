#include "Organizm.h"

Organizm::Organizm(Swiat& swiat)
	:sila(0), inicjatywa(0), pozycjaX(0), pozycjaY(0), swiat(swiat), wiek(0)
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

void Organizm::Dorastanie()
{
	this->wiek++;
}

int Organizm::getWiek()
{
	return this->wiek;
}

void Organizm::Wypisz()
{
	Gotoxy(pozycjaX + 1, pozycjaY + 3);
}

