#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
public:
	Antylopa(int pozycjaX, int pozycjaY, Swiat& swiat);
	Antylopa(int inicjatywa, int sila, int pozycjaX, int pozycjaY, int wiek, Swiat& swiat);
	void Akcja() override;
	void Kolizja(Organizm* organizmy) override;
	void Wypisz() override;
	~Antylopa();


	void RuchN() override;
	void RuchE() override;
	void RuchS() override;
	void RuchW() override;

	void RuchNW() override;
	void RuchNE() override;
	void RuchSE() override;
	void RuchSW() override;
};