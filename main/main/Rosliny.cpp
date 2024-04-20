#include <string>

#include "Rosliny.h"

#include "Definicje.h"

#include "Trawa.h"
#include "Mlecz.h"
#include "WilczeJagody.h"
#include "Guarana.h"
#include "BarszczSosnowskiegp.h"

Roslina::Roslina(Swiat& swiat)
	:Organizm(swiat)
{
	Organizm::sila = 0;
	Organizm::inicjatywa = 0;
}

void Roslina::Akcja()
{
	int szansa = rand() % 100 + 1;
	if (szansa> SZANSA_ROZMNOZENIA)
	{
		int kierunek = rand() % 8;
		int noweX = this->GetPozycjaX();
		int noweY = this->GetPozycjaY();
		switch (kierunek)
		{
		case N:
			if (noweY!=1)
			{
				noweY--;
			}
			break;
		case S:
			if (noweY != swiat.GetWysokosc())
			{
				noweY++;
			}
			break;
		case W:
			if (noweX != 1)
			{
				noweX--;
			}
			break;
		case E:
			if (noweX != swiat.GetSzerokosc())
			{
				noweX++;
			}
			break;
		case NE:
			if (noweX != swiat.GetSzerokosc() && noweY != 1)
			{
				noweX++;
				noweY--;
			}
			break;
		case NW:
			if (noweX != 1 && noweY != 1)
			{
				noweX--;
				noweY--;
			}
			break;
		case SE:
			if (noweX != swiat.GetSzerokosc() && noweY != swiat.GetWysokosc())
			{
				noweX++;
				noweY++;
			}
			break;
		case SW:
			if (noweX != 1 && noweY != swiat.GetWysokosc())
			{
				noweX--;
				noweY++;
			}
			break;
		default:
			break;
		}

		if (this->pozycjaX != noweX || this->pozycjaY != noweY)
		{
			if (!swiat.OrganizmXY(noweX, noweY))
			{
				if (dynamic_cast<Trawa*>(this))
				{
					swiat.DodajOrganizm(new Trawa(noweX, noweY, swiat));
					std::string log = "Trawa z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
				else if (dynamic_cast<Mlecz*>(this)) {
					swiat.DodajOrganizm(new Mlecz(noweX, noweY, swiat));
					std::string log = "Mlecz z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
				else if (dynamic_cast<Guarana*>(this)) {
					swiat.DodajOrganizm(new Guarana(noweX, noweY, swiat));
					std::string log = "Guarana z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
				else if (dynamic_cast<BarszczSosnowskiego*>(this)) {
					swiat.DodajOrganizm(new BarszczSosnowskiego(noweX, noweY, swiat));
					std::string log = "Barszcz Sosnowskiego z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
				else if (dynamic_cast<WilczeJagody*>(this)) {
					swiat.DodajOrganizm(new WilczeJagody(noweX, noweY, swiat));
					std::string log = "Wilcze Jagody z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
			}
		}
	}
}

void Roslina::Kolizja()
{
}

void Roslina::Wypisz()
{
}
