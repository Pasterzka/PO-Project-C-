#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	int zdolnosc;
public:
	Czlowiek(int pozycjaX, int pozycjaY, Swiat& swiat);
	void Akcja() override;
	void Kolizja(Organizm* organizmy) override;
	void Wypisz() override;
	~Czlowiek();

	void CialoPalenie();

	void RuchN() override; 
	void RuchE() override;
	void RuchS() override;
	void RuchW() override;

	void RuchNW() override;
	void RuchNE() override;
	void RuchSE() override;
	void RuchSW() override;
};