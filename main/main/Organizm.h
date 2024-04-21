#pragma once
#pragma once
#include "Swiat.h"

class Swiat;

class Organizm
{
protected:
	int sila;
	double inicjatywa;
	int pozycjaX;
	int pozycjaY;
	int wiek;
	Swiat& swiat;

public:
	Organizm(Swiat& swiat);
	int GetPozycjaX() const;
	int GetPozycjaY() const;
	void SetPozycjaX(int x);
	void SetPozycjaY(int y);
	void Dorastanie();
	int getWiek();
	double getInicjatywa() const;
	void setSila(int i);
	int getSila();
	virtual void Akcja() = 0;
	virtual void Kolizja(Organizm* organizmy) = 0;
	virtual void Wypisz();
	void SetInicjatywa(int i);
	//~Organizm();
};