#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::sila = 99;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

void WilczeJagody::Akcja()
{
	Roslina::Akcja();
}

void WilczeJagody::Kolizja()
{
}

void WilczeJagody::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "J";
}

WilczeJagody::~WilczeJagody()
{
}
