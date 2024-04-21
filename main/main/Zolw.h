#pragma once
#include "Zwierze.h"


class Zolw : public Zwierze {
public:
	Zolw(int pozycjaX, int pozycjaY, Swiat& swiat);
	Zolw(int inicjatywa, int sila, int pozycjaX, int pozycjaY, int wiek, Swiat& swiat);
	void Akcja() override;
	void Kolizja(Organizm* organizmy) override;
	void Wypisz() override;
	bool Szansa();
	~Zolw();
};