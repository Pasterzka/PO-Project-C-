#pragma once

#include "Zwierze.h"

class Owca : public Zwierze {
public:
	Owca(int pozycjaX, int pozycjaY, Swiat& swiat);
	Owca(int inicjatywa, int sila, int pozycjaX, int pozycjaY, int wiek, Swiat& swiat);
	void Akcja() override;
	void Kolizja(Organizm* organizmy) override;
	void Wypisz() override;
	~Owca();
};