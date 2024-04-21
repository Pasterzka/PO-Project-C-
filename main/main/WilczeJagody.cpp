#include "WilczeJagody.h"

#include <string>

WilczeJagody::WilczeJagody(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::sila = 99;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

WilczeJagody::WilczeJagody(int inicjatywa, int sila, int pozycjaX, int pozycjaY, int wiek, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::sila = sila;
	Organizm::inicjatywa = inicjatywa;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
	Organizm::wiek = wiek;
}

void WilczeJagody::Akcja()
{
	Roslina::Akcja();
}

void WilczeJagody::Kolizja(Organizm* organizmy)
{
	if (organizmy->getSila()>sila)
	{
		std::string nazwa = swiat.GetTypOrganizmu(organizmy);
		int x = organizmy->GetPozycjaX();
		int y = organizmy->GetPozycjaY();
		int index = swiat.getIndexOrganizmu(x, y);
		swiat.UsunOrganizm(index);

		std::string log = "Wilcze jagody (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") zostal zniszczony przez " + nazwa + ".\n";
		swiat.DodajLog(log);

		int index2 = swiat.getIndexOrganizmu(pozycjaX, pozycjaY);
		swiat.UsunOrganizm(index2);

	}
	else {
		int x = organizmy->GetPozycjaX();
		int y = organizmy->GetPozycjaY();
		int index = swiat.getIndexOrganizmu(x, y);
		swiat.UsunOrganizm(index);
	}

	
}

void WilczeJagody::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "J";
}

WilczeJagody::~WilczeJagody()
{
}
