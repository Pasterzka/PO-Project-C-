#include "Antylopa.h"
#include "Definicje.h"

Antylopa::Antylopa(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Zwierze(swiat)
{
	Organizm::sila = 4;
	Organizm::inicjatywa = 4;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

void Antylopa::Akcja()
{
	int kierunek = rand() % 4;
	switch (kierunek)
	{
	case N:
		if (pozycjaY != 2)
		{
			pozycjaY-=2;
		}
		break;
	case E:
		if (pozycjaX != swiat.GetSzerokosc()-1)
		{
			pozycjaX+=2;
		}
		break;
	case S:
		if (pozycjaY != swiat.GetWysokosc()-1)
		{
			pozycjaY+=2;
		}
		break;
	case W:
		if (pozycjaX != 2)
		{
			pozycjaX-=2;
		}
		break;
	default:
		break;
	}
}

void Antylopa::Kolizja(Organizm* organizmy)
{
	std::string nazwa = swiat.GetTypOrganizmu(organizmy);
	std::string log = "";
	int x = pozycjaX;
	int y = pozycjaY;
	int los = rand() % 2;
	if (los ==1)
	{
		//doko�cz
	}
}

void Antylopa::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "A";
}

Antylopa::~Antylopa()
{
}
