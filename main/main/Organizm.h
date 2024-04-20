#pragma once
#pragma once
#include "Swiat.h"

class Swiat;

class Organizm
{
protected:
	int sila;
	int inicjatywa;
	int pozycjaX;
	int pozycjaY;
	int wiek;
	Swiat& swiat;

public:
	Organizm(Swiat& swiat);
	int GetPozycjaX() const;
	int GetPozycjaY() const;
	void Dorastanie();
	int getWiek();
	virtual void Akcja() = 0;
	virtual void Kolizja() = 0;
	virtual void Wypisz();
	//~Organizm();
};