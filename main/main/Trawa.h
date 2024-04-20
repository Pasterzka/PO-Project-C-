#pragma once
#include "Rosliny.h"

class Trawa : public Roslina {
public:
	Trawa(int pozycjaX, int pozycjaY, Swiat& swiat);
	void Kolizja(Organizm* organizmy) override;
	void Akcja() override;
	void Wypisz() override;
	~Trawa();
};