#include "Zwierze.h"
#include "Definicje.h"

Zwierze::Zwierze(Swiat& swiat)
	:Organizm(swiat)
{
}

void Zwierze::Akcja()
{

	int kierunek = rand() % 4;
	switch (kierunek)
	{
	case N:
		if (pozycjaY!=1)
		{
			pozycjaY--;
		}
		break;
	case E:
		if (pozycjaX!=swiat.GetSzerokosc())
		{
			pozycjaX++;
		}
		break;
	case S:
		if (pozycjaY != swiat.GetWysokosc())
		{
			pozycjaY++;
		}
		break;
	case W:
		if (pozycjaX != 1)
		{
			pozycjaX--;
		}
		break;
	default:
		break;
	}
}

void Zwierze::Kolizja()
{
}

void Zwierze::Wypisz()
{
}
