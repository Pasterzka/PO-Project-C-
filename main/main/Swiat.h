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

public:
	Swiat(unsigned wysokosc, unsigned szerokosc, std::vector<Organizm*>* organizmy);
	//World(unsigned width, unsigned height);
	void DodajOrganizm(Organizm* organizmy);
	unsigned GetWysokosc() const;
	unsigned GetSzerokosc() const;
	void NastêpnaTura();
	void Wypisz();
	~Swiat();
};