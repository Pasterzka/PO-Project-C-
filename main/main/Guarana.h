#pragma once
#include "Rosliny.h"

class Guarana : public Roslina {
public:
	Guarana(int pozycjaX, int pozycjaY, Swiat& swiat);
	void Akcja() override;
	void Kolizja(Organizm* organizmy) override;
	void Wypisz() override;
	~Guarana();
};