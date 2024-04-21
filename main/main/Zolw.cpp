#include "Zolw.h"
#include <string>

Zolw::Zolw(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Zwierze(swiat)
{
	Organizm::inicjatywa = 1;
	Organizm::sila = 2;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

void Zolw::Akcja()
{
	if (Szansa())
	{
		Zwierze::Akcja();
	}
	else {
		std::string log = "";
		int x = pozycjaX;
		int y = pozycjaY;

		log = "Zolw z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaX) + ") pozostaje na swoim miejscu za mala szansa na ruch.\n";
		swiat.DodajLog(log);
	}
}

void Zolw::Kolizja(Organizm* organizmy)
{
	std::string nazwa = swiat.GetTypOrganizmu(organizmy);
	std::string log = "";
	int x = pozycjaX;
	int y = pozycjaY;
	
	log = "Zolw z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaX) + ") odbil atak " + nazwa + ".";
	swiat.DodajLog(log);
}

void Zolw::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "Z";
}

bool Zolw::Szansa()
{
	int los = rand() % 100 + 1;
	if (los>20)
	{
		return false;
	}
	else {
		return true;
	}
}

Zolw::~Zolw()
{
}
