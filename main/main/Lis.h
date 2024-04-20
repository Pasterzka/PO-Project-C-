#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
public:
	Lis(int pozycjaX, int pozycjaY, Swiat& swiat);
	void Akcja() override;
	void Kolizja() override;
	void Wypisz() override;
	~Lis();
};