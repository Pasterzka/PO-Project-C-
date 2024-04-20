#include "BarszczSosnowskiegp.h"

BarszczSosnowskiego::BarszczSosnowskiego(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

void BarszczSosnowskiego::Akcja()
{
	Roslina::Akcja();
}

void BarszczSosnowskiego::Kolizja()
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
