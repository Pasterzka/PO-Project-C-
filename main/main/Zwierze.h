#pragma once
#include "Organizm.h"


class Zwierze : public Organizm{
public:
	Zwierze(Swiat& swiat);
	virtual void Akcja() override;
	virtual void Kolizja(Organizm* organizmy) override;
	virtual void Wypisz() override;

	virtual void RuchN();
	virtual void RuchE();
	virtual void RuchS();
	virtual void RuchW();

	virtual void RuchNE();
	virtual void RuchNW();
	virtual void RuchSE();
	virtual void RuchSW();
};