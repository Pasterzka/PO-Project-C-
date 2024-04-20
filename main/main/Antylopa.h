#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(int pozycjaX, int pozycjaY, Swiat& swiat);
	void Akcja() override;
	void Kolizja(Organizm* organizmy) override;
	void Wypisz() override;
	~Antylopa();
};