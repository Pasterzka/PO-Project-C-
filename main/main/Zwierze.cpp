#include "Zwierze.h"
#include "Definicje.h"
#include "Rosliny.h"


#include "Czlowiek.h"
#include "Owca.h"
#include "Wilk.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"

#include <string>

Zwierze::Zwierze(Swiat& swiat)
	:Organizm(swiat)
{
}

void Zwierze::Akcja()
{

	int kierunek = rand() % 8;
	switch (kierunek)
	{
	case N:
		RuchN();
		break;
	case E:
		RuchE();
		break;
	case S:
		RuchS();
		break;
	case W:
		RuchW();
		break;
	case NW:
		RuchNW();
		break;
	case NE:
		RuchNE();
		break;
	case SW:
		RuchSW();
		break;
	case SE:
		RuchSE();
		break;
	default:
		break;
	}
}

void Zwierze::Kolizja(Organizm* organizmy)
{
	int los = rand() % 2;
	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	if (los == 1)
	{
		int kierunek = rand() % 8;
		int noweX = this->GetPozycjaX();
		int noweY = this->GetPozycjaY();
		switch (kierunek)
		{
		case N:
			if (noweY != 1)
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

		if ((this->pozycjaX != noweX || this->pozycjaY != noweY) && (organizmy->GetPozycjaX() != noweX || organizmy->GetPozycjaY() != noweY))
		{
			if (!swiat.OrganizmXY(noweX, noweY))
			{
				if (thisNazwa == "Wilk")
				{
					swiat.DodajOrganizm(new Wilk(noweX, noweY, swiat));
					std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
				else if (thisNazwa == "Zolw")
				{
					swiat.DodajOrganizm(new Zolw(noweX, noweY, swiat));
					std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
				else if (thisNazwa == "Owca")
				{
					swiat.DodajOrganizm(new Owca(noweX, noweY, swiat));
					std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
				else if (thisNazwa == "Antylopa")
				{
					swiat.DodajOrganizm(new Antylopa(noweX, noweY, swiat));
					std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
				else if (thisNazwa == "Lis")
				{
					swiat.DodajOrganizm(new Lis(noweX, noweY, swiat));
					std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
			}
			else {
				std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") nie udalo sie rozmnozyc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
				swiat.DodajLog(log);
			}
			
		}
		else {
			std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") nie udalo sie rozmnozyc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
			swiat.DodajLog(log);
		}
		

	}
	else {
		int kierunek = rand() % 8;
		int noweX = organizmy->GetPozycjaX();
		int noweY = organizmy->GetPozycjaY();
		switch (kierunek)
		{
		case N:
			if (noweY != 1)
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
		std::string thisNazwa = swiat.GetTypOrganizmu(this);
		if ((this->pozycjaX != noweX || this->pozycjaY != noweY) && (organizmy->GetPozycjaX() != noweX || organizmy->GetPozycjaY() != noweY))
		{
			if (!swiat.OrganizmXY(noweX, noweY))
			{
				if (thisNazwa == "Wilk")
				{
					swiat.DodajOrganizm(new Wilk(noweX, noweY, swiat));
					std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
				else if (thisNazwa == "Zolw")
				{
					swiat.DodajOrganizm(new Zolw(noweX, noweY, swiat));
					std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
				else if (thisNazwa == "Owca")
				{
					swiat.DodajOrganizm(new Owca(noweX, noweY, swiat));
					std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
				else if (thisNazwa == "Antylopa")
				{
					swiat.DodajOrganizm(new Antylopa(noweX, noweY, swiat));
					std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
				else if (thisNazwa == "Lis")
				{
					swiat.DodajOrganizm(new Lis(noweX, noweY, swiat));
					std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") rozmnozyla sie na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
					swiat.DodajLog(log);
				}
			}
			else {
				std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") nie udalo sie rozmnozyc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
				swiat.DodajLog(log);
			}

		}
		else {
			std::string log = thisNazwa + " z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") nie udalo sie rozmnozyc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
			swiat.DodajLog(log);
		}

	}
}

void Zwierze::Wypisz()
{
}

void Zwierze::RuchN()
{

	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	int noweY = pozycjaY - 1;
	int noweX = pozycjaX;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	if (pozycjaY != 1)
	{
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY--;
			std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
			swiat.DodajLog(log);
		}
		else {
			Organizm* przeciwnik = swiat.GetOrganizm(noweX, noweY);
			int przeciwnikX = przeciwnik->GetPozycjaX();
			int przeciwnikY = przeciwnik->GetPozycjaY();
			std::string nazwa = swiat.GetTypOrganizmu(przeciwnik);
			std::string log = "";
			if (dynamic_cast<Roslina*>(przeciwnik))
			{
				if (nazwa == "Wilcze Jagody")
				{
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{

					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					if (nazwa == "Barszcz Sosnowskiego")
					{
						log += thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";

					}
					Organizm::pozycjaY--;
					swiat.DodajLog(log);
				}
				else {
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (swiat.CzyKolizja(this, przeciwnik))
				{
					if (this->wiek > 2 && przeciwnik->getWiek() > 2)
					{
						Zwierze::Kolizja(przeciwnik);
					}
				}
				else if (swiat.CzyOdbil(this) && nazwa == "Zolw")
				{
					przeciwnik->Kolizja(this);
				}
				else if (nazwa == "Antylopa")
				{
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaY--;
				}
				else {
					log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}
	else {
		std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") nieudany ruch.\n";
		swiat.DodajLog(log);
	}
}

void Zwierze::RuchE()
{
	std::string thisNazwa = swiat.GetTypOrganizmu(this);

	int noweY = pozycjaY;
	int noweX = pozycjaX + 1;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	if (pozycjaX != swiat.GetSzerokosc())
	{
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaX++;
			std::string log = thisNazwa +" z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
			swiat.DodajLog(log);
		}
		else {
			Organizm* przeciwnik = swiat.GetOrganizm(noweX, noweY);
			int przeciwnikX = przeciwnik->GetPozycjaX();
			int przeciwnikY = przeciwnik->GetPozycjaY();
			std::string nazwa = swiat.GetTypOrganizmu(przeciwnik);
			std::string log = "";
			if (dynamic_cast<Roslina*>(przeciwnik))
			{
				if (nazwa == "Wilcze Jagody")
				{
					std::string log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					if (nazwa == "Barszcz Sosnowskiego")
					{
						log += thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";

					}
					Organizm::pozycjaX++;
					swiat.DodajLog(log);
				}
				else {
					std::string log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (swiat.CzyKolizja(this, przeciwnik))
				{
					if (this->wiek > 2 && przeciwnik->getWiek() > 2)
					{
						//tutaj bêdzie kolizja
					}
					Zwierze::Kolizja(przeciwnik);
				}
				else if (swiat.CzyOdbil(this) && nazwa == "Zolw")
				{
					przeciwnik->Kolizja(this);
				}
				else if (nazwa == "Antylopa")
				{
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaX++;
				}
				else {
					log = thisNazwa+" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}
	else {
		std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") nieudany ruch.\n";
		swiat.DodajLog(log);
	}
}

void Zwierze::RuchS()
{
	int noweY = pozycjaY + 1;
	int noweX = pozycjaX;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	if (pozycjaY != swiat.GetWysokosc())
	{
		
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY++;
			std::string log = thisNazwa +" z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
			swiat.DodajLog(log);
		}
		else {
			Organizm* przeciwnik = swiat.GetOrganizm(noweX, noweY);
			int przeciwnikX = przeciwnik->GetPozycjaX();
			int przeciwnikY = przeciwnik->GetPozycjaY();
			std::string nazwa = swiat.GetTypOrganizmu(przeciwnik);
			std::string log = "";
			if (dynamic_cast<Roslina*>(przeciwnik))
			{
				if (nazwa == "Wilcze Jagody")
				{
					std::string log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					if (nazwa == "Barszcz Sosnowskiego")
					{
						log += thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";

					}
					Organizm::pozycjaY++;
					swiat.DodajLog(log);
				}
				else {
					std::string log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (swiat.CzyKolizja(this, przeciwnik))
				{
					if (this->wiek > 2 && przeciwnik->getWiek() > 2)
					{
						//tutaj bêdzie kolizja
					}
					Zwierze::Kolizja(przeciwnik);
				}
				else if (swiat.CzyOdbil(this) && nazwa == "Zolw")
				{
					przeciwnik->Kolizja(this);
				}
				else if (nazwa == "Antylopa")
				{
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaY++;
				}
				else {
					log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}
	else {
		std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") nieudany ruch.\n";
		swiat.DodajLog(log);
	}
}

void Zwierze::RuchW()
{
	int noweY = pozycjaY;
	int noweX = pozycjaX - 1;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	if (pozycjaX != 1)
	{
		int noweY = pozycjaY;
		int noweX = pozycjaX - 1;
		int stareY = pozycjaY;
		int stareX = pozycjaX;
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaX--;
			std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
			swiat.DodajLog(log);
		}
		else {
			Organizm* przeciwnik = swiat.GetOrganizm(noweX, noweY);
			int przeciwnikX = przeciwnik->GetPozycjaX();
			int przeciwnikY = przeciwnik->GetPozycjaY();
			std::string nazwa = swiat.GetTypOrganizmu(przeciwnik);
			std::string log = "";
			if (dynamic_cast<Roslina*>(przeciwnik))
			{
				if (nazwa == "Wilcze Jagody")
				{
					std::string log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					if (nazwa == "Barszcz Sosnowskiego")
					{
						log += thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";

					}
					Organizm::pozycjaX--;
					swiat.DodajLog(log);
				}
				else {
					std::string log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (swiat.CzyKolizja(this, przeciwnik))
				{
					if (this->wiek > 2 && przeciwnik->getWiek() > 2)
					{
						//tutaj bêdzie kolizja
					}
					Zwierze::Kolizja(przeciwnik);
				}
				else if (swiat.CzyOdbil(this) && nazwa == "Zolw")
				{
					przeciwnik->Kolizja(this);
				}
				else if (nazwa == "Antylopa")
				{
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaX--;
				}
				else {
					log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}else {
		std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") nieudany ruch.\n";
		swiat.DodajLog(log);
	}
}

void Zwierze::RuchNE()
{

	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	int noweY = pozycjaY - 1;
	int noweX = pozycjaX + 1;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	if (pozycjaY != 1 && pozycjaX != swiat.GetSzerokosc())
	{
		
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY--;
			Organizm::pozycjaX++;
			std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
			swiat.DodajLog(log);
		}
		else {
			Organizm* przeciwnik = swiat.GetOrganizm(noweX, noweY);
			int przeciwnikX = przeciwnik->GetPozycjaX();
			int przeciwnikY = przeciwnik->GetPozycjaY();
			std::string nazwa = swiat.GetTypOrganizmu(przeciwnik);
			std::string log = "";
			if (dynamic_cast<Roslina*>(przeciwnik))
			{
				if (nazwa == "Wilcze Jagody")
				{
					std::string log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{

					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					if (nazwa == "Barszcz Sosnowskiego")
					{
						log += thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";

					}
					Organizm::pozycjaY--;
					Organizm::pozycjaX++;
					swiat.DodajLog(log);
				}
				else {
					std::string log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (swiat.CzyKolizja(this, przeciwnik))
				{
					if (this->wiek > 2 && przeciwnik->getWiek() > 2)
					{
						//tutaj bêdzie kolizja
					}
					Zwierze::Kolizja(przeciwnik);
				}
				else if (swiat.CzyOdbil(this) && nazwa == "Zolw")
				{
					przeciwnik->Kolizja(this);
				}
				else if (nazwa == "Antylopa")
				{
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaY--;
					Organizm::pozycjaX++;
				}
				else {
					log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}
	else {
		std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") nieudany ruch.\n";
		swiat.DodajLog(log);
	}
}

void Zwierze::RuchNW()
{

	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	int noweY = pozycjaY - 1;
	int noweX = pozycjaX - 1;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	if (pozycjaY != 1 && pozycjaX != 1)
	{
		
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY--;
			Organizm::pozycjaX--;
			std::string log = thisNazwa +" z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
			swiat.DodajLog(log);
		}
		else {
			Organizm* przeciwnik = swiat.GetOrganizm(noweX, noweY);
			int przeciwnikX = przeciwnik->GetPozycjaX();
			int przeciwnikY = przeciwnik->GetPozycjaY();
			std::string nazwa = swiat.GetTypOrganizmu(przeciwnik);
			std::string log = "";
			if (dynamic_cast<Roslina*>(przeciwnik))
			{
				if (nazwa == "Wilcze Jagody")
				{
					std::string log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{

					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					if (nazwa == "Barszcz Sosnowskiego")
					{
						log += thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";

					}
					Organizm::pozycjaY--;
					Organizm::pozycjaX--;
					swiat.DodajLog(log);
				}
				else {
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (swiat.CzyKolizja(this, przeciwnik))
				{
					if (this->wiek > 2 && przeciwnik->getWiek() > 2)
					{
						//tutaj bêdzie kolizja
					}
					Zwierze::Kolizja(przeciwnik);
				}
				else if (swiat.CzyOdbil(this) && nazwa == "Zolw")
				{
					przeciwnik->Kolizja(this);
				}
				else if (nazwa == "Antylopa")
				{
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					std::string log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaY--;
					Organizm::pozycjaX--;
				}
				else {
					log = thisNazwa +" z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}
	else {
		std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") nieudany ruch.\n";
		swiat.DodajLog(log);
	}
}

void Zwierze::RuchSE()
{

	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	int noweY = pozycjaY + 1;
	int noweX = pozycjaX + 1;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	if (pozycjaY != swiat.GetWysokosc() && pozycjaX != swiat.GetSzerokosc())
	{
		
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY++;
			Organizm::pozycjaX++;
			std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
			swiat.DodajLog(log);
		}
		else {
			Organizm* przeciwnik = swiat.GetOrganizm(noweX, noweY);
			int przeciwnikX = przeciwnik->GetPozycjaX();
			int przeciwnikY = przeciwnik->GetPozycjaY();
			std::string nazwa = swiat.GetTypOrganizmu(przeciwnik);
			std::string log = "";
			if (dynamic_cast<Roslina*>(przeciwnik))
			{
				if (nazwa == "Wilcze Jagody")
				{
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{

					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					if (nazwa == "Barszcz Sosnowskiego")
					{
						log += thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";

					}
					Organizm::pozycjaY++;
					Organizm::pozycjaX++;
					swiat.DodajLog(log);
				}
				else {
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (swiat.CzyKolizja(this, przeciwnik))
				{
					if (this->wiek > 2 && przeciwnik->getWiek() > 2)
					{
						//tutaj bêdzie kolizja
					}
					Zwierze::Kolizja(przeciwnik);
				}
				else if (swiat.CzyOdbil(this) && nazwa == "Zolw")
				{
					przeciwnik->Kolizja(this);
				}
				else if (nazwa == "Antylopa")
				{
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaY++;
					Organizm::pozycjaX++;
				}
				else {
					log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}
	else {
		std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") nieudany ruch.\n";
		swiat.DodajLog(log);
	}

}

void Zwierze::RuchSW()
{
	int noweY = pozycjaY + 1;
	int noweX = pozycjaX - 1;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	if (pozycjaY != swiat.GetWysokosc() && pozycjaX != 1)
	{
		
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY++;
			Organizm::pozycjaX--;
			std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
			swiat.DodajLog(log);
		}
		else {
			Organizm* przeciwnik = swiat.GetOrganizm(noweX, noweY);
			int przeciwnikX = przeciwnik->GetPozycjaX();
			int przeciwnikY = przeciwnik->GetPozycjaY();
			std::string nazwa = swiat.GetTypOrganizmu(przeciwnik);
			std::string log = "";
			if (dynamic_cast<Roslina*>(przeciwnik))
			{
				if (nazwa == "Wilcze Jagody")
				{
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{

					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					if (nazwa == "Barszcz Sosnowskiego")
					{
						log += thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";

					}
					Organizm::pozycjaY++;
					Organizm::pozycjaX--;
					swiat.DodajLog(log);
				}
				else {
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (swiat.CzyKolizja(this, przeciwnik))
				{
					if (this->wiek > 2 && przeciwnik->getWiek() > 2)
					{
						//tutaj bêdzie kolizja
					}
					Zwierze::Kolizja(przeciwnik);
				}
				else if (swiat.CzyOdbil(this) && nazwa == "Zolw")
				{
					przeciwnik->Kolizja(this);
				}
				else if (nazwa == "Antylopa")
				{
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					std::string log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaY++;
					Organizm::pozycjaX--;
				}
				else {
					log = thisNazwa + " z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}
	else {
		std::string log = thisNazwa + " z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") nieudany ruch.\n";
		swiat.DodajLog(log);
	}
}
