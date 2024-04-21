#include "Lis.h"

#include "Definicje.h"
#include <string>

Lis::Lis(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Zwierze(swiat)
{
	Organizm::inicjatywa = 7;
	Organizm::sila = 3;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

void Lis::Akcja()
{
	int kierunek = rand() % 8;
	switch (kierunek)
	{
	case N:
		if (swiat.OrganizmXY(pozycjaX, pozycjaY-1))
		{
			Lis::Kolizja(swiat.GetOrganizm(pozycjaX, pozycjaY - 1));
		}
		else {
			Zwierze::RuchN();
		}
		break;
	case E:
		if (swiat.OrganizmXY(pozycjaX +1, pozycjaY))
		{
			Lis::Kolizja(swiat.GetOrganizm(pozycjaX+1, pozycjaY));
		}
		else {
			Zwierze::RuchE();
		}
		break;
	case S:
		if (swiat.OrganizmXY(pozycjaX, pozycjaY + 1))
		{
			Lis::Kolizja(swiat.GetOrganizm(pozycjaX, pozycjaY + 1));
		}
		else {
			Zwierze::RuchS();
		}
		break;
	case W:
		if (swiat.OrganizmXY(pozycjaX -1, pozycjaY))
		{
			Lis::Kolizja(swiat.GetOrganizm(pozycjaX-1, pozycjaY));
		}
		else {
			Zwierze::RuchW();
		};
		break;
	case NW:
		if (swiat.OrganizmXY(pozycjaX - 1, pozycjaY - 1))
		{
			Lis::Kolizja(swiat.GetOrganizm(pozycjaX - 1, pozycjaY - 1));
		}
		else {
			Zwierze::RuchNW();
		}
		break;
	case NE:
		if (swiat.OrganizmXY(pozycjaX +1, pozycjaY - 1))
		{
			Lis::Kolizja(swiat.GetOrganizm(pozycjaX + 1, pozycjaY - 1));
		}
		else {
			Zwierze::RuchNE();
		}
		break;
	case SW:
		if (swiat.OrganizmXY(pozycjaX - 1, pozycjaY + 1))
		{
			Lis::Kolizja(swiat.GetOrganizm(pozycjaX - 1, pozycjaY + 1));
		}
		else {
			Zwierze::RuchSW();
		}
		break;
	case SE:
		if (swiat.OrganizmXY(pozycjaX +1, pozycjaY + 1))
		{
			Lis::Kolizja(swiat.GetOrganizm(pozycjaX +1, pozycjaY + 1));
		}
		else {
			Zwierze::RuchSE();
		}
		break;
	default:
		break;
	}
}

void Lis::Kolizja(Organizm* organizmy)
{
	std::string log;
	int noweX = organizmy->GetPozycjaX();
	int noweY = organizmy->GetPozycjaY();
	if (organizmy->getSila()>this->sila)
	{
		log = "Lis z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") pozostaje na swoim miejscu, bo na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") napotkal silniejszego przeciwnika.\n";
		swiat.DodajLog(log);
	}
	else {
		std::string nazwa = swiat.GetTypOrganizmu(organizmy);
		log =  "Lis z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
		swiat.DodajLog(log);
		swiat.UsunOrganizm(swiat.getIndexOrganizmu(noweX, noweY));
		Organizm::pozycjaX = noweX;
		Organizm::pozycjaY = noweY;
	}
}

void Lis::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "L";
}

Lis::~Lis()
{
}
