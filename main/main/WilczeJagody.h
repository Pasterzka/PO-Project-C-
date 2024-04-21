#pragma once
#include "Rosliny.h"

class WilczeJagody : public Roslina {
public:
	WilczeJagody(int pozycjaX, int pozycjaY, Swiat& swiat);
	WilczeJagody(int inicjatywa, int sila, int pozycjaX, int pozycjaY, int wiek, Swiat& swiat);
	void Akcja() override;
	void Kolizja(Organizm* organizmy) override;
	void Wypisz() override;
	~WilczeJagody();
};