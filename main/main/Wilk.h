#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
	Wilk(int pozycjaX, int pozycjaY, Swiat& swiat);
	void Akcja() override;
	void Kolizja() override;
	void Wypisz() override;
	~Wilk();
};