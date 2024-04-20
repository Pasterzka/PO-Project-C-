#pragma once
#include "Zwierze.h"


class Zolw : public Zwierze {
public:
	Zolw(int pozycjaX, int pozycjaY, Swiat& swiat);
	void Akcja() override;
	void Kolizja() override;
	void Wypisz() override;
	bool Szansa();
	~Zolw();
};