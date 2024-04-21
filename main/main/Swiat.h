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
	void NastêpnaTura();
	void Wypisz();
	bool OrganizmXY(int x, int y);
	void CzyscLog();
	void DodajLog(std::string log);
	void DorastanieStart();
	void GetLogi();
	int getIndexOrganizmu(int x, int y);
	void UsunOrganizm(int index);
	Organizm* GetOrganizm(int x, int y);
	std::string GetTypOrganizmu(Organizm* organizm);
	int GetDlougoscOrganizmow();
	bool CzyOdbil(Organizm* organizm);
	bool CzyKolizja(Organizm* organizm, Organizm* organizm2);
	~Swiat();
};