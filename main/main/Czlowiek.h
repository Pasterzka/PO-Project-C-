#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	int zdolnosc;
public:
	Czlowiek(int pozycjaX, int pozycjaY, Swiat& swiat);
	void Akcja() override;
	void Kolizja() override;
	void Wypisz() override;
	~Czlowiek();
};