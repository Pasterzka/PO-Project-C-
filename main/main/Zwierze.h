#pragma once
#include "Organizm.h"


class Zwierze : public Organizm{
public:
	Zwierze(Swiat& swiat);
	virtual void Akcja() override;
	virtual void Kolizja() override;
	virtual void Wypisz() override;
};