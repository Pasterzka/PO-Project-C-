#pragma once
#include "Rosliny.h"

class WilczeJagody : public Roslina {
public:
	WilczeJagody(int pozycjaX, int pozycjaY, Swiat& swiat);
	void Akcja() override;
	void Kolizja() override;
	void Wypisz() override;
	~WilczeJagody();
};