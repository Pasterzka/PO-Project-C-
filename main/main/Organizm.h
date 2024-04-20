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
	int getInicjatywa() const;
	void setSila(int i);
	int getSila();
	virtual void Akcja() = 0;
	virtual void Kolizja(Organizm* organizmy) = 0;
	virtual void Wypisz();
	//~Organizm();
};