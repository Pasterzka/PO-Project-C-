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

void Organizm::SetPozycjaX(int x)
{
	pozycjaX = x;
}

void Organizm::SetPozycjaY(int y)
{
	pozycjaY = y;
}

void Organizm::Dorastanie()
{
	this->wiek++;
}

int Organizm::getWiek()
{
	return this->wiek;
}

double Organizm::getInicjatywa() const
{
	return this->inicjatywa;
}

void Organizm::setSila(int i)
{
	this->sila = sila + i;
}

int Organizm::getSila()
{
	return this->sila;
}


void Organizm::Wypisz()
{
	Gotoxy(pozycjaX + 1, pozycjaY + 3);
}

void Organizm::SetInicjatywa(int i)
{
	this->inicjatywa = i;
}

