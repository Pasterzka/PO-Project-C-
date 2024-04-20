#pragma once
#include <vector>
#include <iostream>
#include "Funkcje.h"

#include "Organizm.h"


class Organizm;

class Swiat
{
private:
	std::vector<Organizm*>* organizmy;
	unsigned wysokosc;
	unsigned szerokosc;
	std::string log;
	int tura;
public:
	Swiat(unsigned wysokosc, unsigned szerokosc, std::vector<Organizm*>* organizmy);
	//World(unsigned width, unsigned height);
	void DodajOrganizm(Organizm* organizmy);
	unsigned GetWysokosc() const;
	unsigned GetSzerokosc() const;
	void NastÍpnaTura();
	void Wypisz();
	bool OrganizmXY(int x, int y);
	void CzyscLog();
	void DodajLog(std::string log);
	void DorastanieStart();
	~Swiat();
};