#pragma once
#include "Rosliny.h"

class Mlecz : public Roslina {
public:
	Mlecz(int pozycjaX, int pozycjaY, Swiat& swiat);
	void Akcja() override;
	void Wypisz() override;
	void Kolizja(Organizm* organizmy) override;
	~Mlecz();
};