#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
public:
	Roslina(Swiat& swiat);
	void Akcja() override;
	void Kolizja(Organizm* organizmy) override;
	void Wypisz() override;
};