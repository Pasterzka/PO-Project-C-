#include "BarszczSosnowskiegp.h"

BarszczSosnowskiego::BarszczSosnowskiego(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::sila = 0;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

void BarszczSosnowskiego::Akcja()
{
	Roslina::Akcja();
}

void BarszczSosnowskiego::Kolizja(Organizm* organizmy)
{
}

void BarszczSosnowskiego::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "B";
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}
