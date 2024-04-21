#pragma once
#include "Rosliny.h"

class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego(int pozycjaX, int pozycjaY, Swiat& swiat);
	BarszczSosnowskiego(int inicjatywa, int sila, int pozycjaX, int pozycjaY, int wiek, Swiat& swiat);
	void Akcja() override;
	void Kolizja(Organizm* organizmy) override;
	void Wypisz() override;
	void Zdolnosc();
	~BarszczSosnowskiego();
};