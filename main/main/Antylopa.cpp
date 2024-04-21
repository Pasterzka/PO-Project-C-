#include "Antylopa.h"
#include "Definicje.h"

#include "Rosliny.h"


#include "Czlowiek.h"
#include "Owca.h"
#include "Wilk.h"
#include "Lis.h"
#include "Zolw.h"

#include <string>

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

void Antylopa::Kolizja(Organizm* organizmy)
{
	std::string nazwa = swiat.GetTypOrganizmu(organizmy);
	std::string log = "";
	int x = pozycjaX;
	int y = pozycjaY;
	int noweX = organizmy->GetPozycjaX();
	int noweY = organizmy->GetPozycjaY();
	int los = rand() % 2;
	if (los ==1)
	{
		//uczieczka
		if (!swiat.OrganizmXY(x,y-1) && y != 1)
		{
			log = "Antylopa z (" + std::to_string(x) + " " + std::to_string(y) + ") ucieczka udana na (" + std::to_string(x) + " " + std::to_string(y-1) + ").\n";
			swiat.DodajLog(log);
			Organizm::pozycjaX = x;
			Organizm::pozycjaY = y-1;
			log = nazwa + " z (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") przeszedl na (" + std::to_string(x) + " " + std::to_string(y) + ").\n";
			swiat.DodajLog(log);
			organizmy->SetPozycjaX(x);
			organizmy->SetPozycjaY(y);
		}
		else if(!swiat.OrganizmXY(x + 1, y - 1) && y != 1 && x !=swiat.GetSzerokosc())
		{
			log = "Antylopa z (" + std::to_string(x) + " " + std::to_string(y) + ") ucieczka udana na (" + std::to_string(x + 1) + " " + std::to_string(y - 1) + ").\n";
			swiat.DodajLog(log);
			Organizm::pozycjaX = x + 1;
			Organizm::pozycjaY = y - 1;
			log = nazwa + " z (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") przeszedl na (" + std::to_string(x) + " " + std::to_string(y) + ").\n";
			swiat.DodajLog(log);
			organizmy->SetPozycjaX(x);
			organizmy->SetPozycjaY(y);
		}
		else if (!swiat.OrganizmXY(x + 1, y ) && x != swiat.GetSzerokosc())
		{
			log = "Antylopa z (" + std::to_string(x) + " " + std::to_string(y) + ") ucieczka udana na (" + std::to_string(x + 1) + " " + std::to_string(y) + ").\n";
			swiat.DodajLog(log);
			Organizm::pozycjaX = x + 1;
			Organizm::pozycjaY = y;
			log = nazwa + " z (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") przeszedl na (" + std::to_string(x) + " " + std::to_string(y) + ").\n";
			swiat.DodajLog(log);
			organizmy->SetPozycjaX(x);
			organizmy->SetPozycjaY(y);
		}
		else if (!swiat.OrganizmXY(x + 1, y + 1) && y != swiat.GetWysokosc() && x != swiat.GetSzerokosc())
		{
			log = "Antylopa z (" + std::to_string(x) + " " + std::to_string(y) + ") ucieczka udana na (" + std::to_string(x + 1) + " " + std::to_string(y + 1) + ").\n";
			swiat.DodajLog(log);
			Organizm::pozycjaX = x + 1;
			Organizm::pozycjaY = y + 1;
			log = nazwa + " z (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") przeszedl na (" + std::to_string(x) + " " + std::to_string(y) + ").\n";
			swiat.DodajLog(log);
			organizmy->SetPozycjaX(x);
			organizmy->SetPozycjaY(y);
		}
		else if (!swiat.OrganizmXY(x , y + 1) && y != swiat.GetSzerokosc())
		{
			log = "Antylopa z (" + std::to_string(x) + " " + std::to_string(y) + ") ucieczka udana na (" + std::to_string(x) + " " + std::to_string(y + 1) + ").\n";
			swiat.DodajLog(log);
			Organizm::pozycjaX = x;
			Organizm::pozycjaY = y + 1;
			log = nazwa + " z (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") przeszedl na (" + std::to_string(x) + " " + std::to_string(y) + ").\n";
			swiat.DodajLog(log);
			organizmy->SetPozycjaX(x);
			organizmy->SetPozycjaY(y);
		}
		else if (!swiat.OrganizmXY(x - 1, y + 1) && y != swiat.GetWysokosc() && x != 1)
		{
			log = "Antylopa z (" + std::to_string(x) + " " + std::to_string(y) + ") ucieczka udana na (" + std::to_string(x - 1) + " " + std::to_string(y + 1) + ").\n";
			swiat.DodajLog(log);
			Organizm::pozycjaX = x - 1;
			Organizm::pozycjaY = y + 1;
			log = nazwa + " z (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") przeszedl na (" + std::to_string(x) + " " + std::to_string(y) + ").\n";
			swiat.DodajLog(log);
			organizmy->SetPozycjaX(x);
			organizmy->SetPozycjaY(y);
		}
		else if (!swiat.OrganizmXY(x - 1, y) && x != 1)
		{
			log = "Antylopa z (" + std::to_string(x) + " " + std::to_string(y) + ") ucieczka udana na (" + std::to_string(x - 1) + " " + std::to_string(y) + ").\n";
			swiat.DodajLog(log);
			Organizm::pozycjaX = x - 1;
			Organizm::pozycjaY = y;
			log = nazwa + " z (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") przeszedl na (" + std::to_string(x) + " " + std::to_string(y) + ").\n";
			swiat.DodajLog(log);
			organizmy->SetPozycjaX(x);
			organizmy->SetPozycjaY(y);
		}
		else if (!swiat.OrganizmXY(x - 1, y - 1) && y != 1 && x != 1)
		{
			log = "Antylopa z (" + std::to_string(x) + " " + std::to_string(y) + ") ucieczka udana na (" + std::to_string(x - 1) + " " + std::to_string(y - 1) + ").\n";
			swiat.DodajLog(log);
			Organizm::pozycjaX = x - 1;
			Organizm::pozycjaY = y - 1;
			log = nazwa + " z (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") przeszedl na (" + std::to_string(x) + " " + std::to_string(y) + ").\n";
			swiat.DodajLog(log);
			organizmy->SetPozycjaX(x);
			organizmy->SetPozycjaY(y);
		}
		else {
			log = "Antylopa z (" + std::to_string(x) + " " + std::to_string(y) + ") ucieczka nieudana. ";
			swiat.DodajLog(log);
			if (this->sila>organizmy->getSila())
			{
				log = "Antylopa z (" + std::to_string(x) + " " + std::to_string(y) + ") zabila atakujacego " + nazwa + "z (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
				swiat.DodajLog(log);
				swiat.UsunOrganizm(swiat.getIndexOrganizmu(noweX, noweY));
			}
			else {
				log = nazwa + " z (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") przeszedl na (" + std::to_string(x) + " " + std::to_string(y) + ") zabijajac Antylopa.\n";
				swiat.DodajLog(log);
				swiat.UsunOrganizm(swiat.getIndexOrganizmu(x,y));
				organizmy->SetPozycjaX(x);
				organizmy->SetPozycjaY(y);
			}
		}
	}
	else {
		if (this->sila > organizmy->getSila())
		{
			log = "Antylopa z (" + std::to_string(x) + " " + std::to_string(y) + ") zabila atakujacego " + nazwa + "z (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
			swiat.DodajLog(log);
			swiat.UsunOrganizm(swiat.getIndexOrganizmu(noweX, noweY));
		}
		else {
			log = nazwa + " z (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") przeszedl na (" + std::to_string(x) + " " + std::to_string(y) + ") zabijajac Antylopa.\n";
			swiat.DodajLog(log);
			swiat.UsunOrganizm(swiat.getIndexOrganizmu(x, y));
			organizmy->SetPozycjaX(x);
			organizmy->SetPozycjaY(y);
		}
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

void Antylopa::RuchN()
{

	{

		std::string thisNazwa = swiat.GetTypOrganizmu(this);
		int noweY = pozycjaY - 2;
		int noweX = pozycjaX;
		int stareY = pozycjaY;
		int stareX = pozycjaX;
		if (pozycjaY > 2)
		{
			if (!swiat.OrganizmXY(noweX, noweY))
			{
				Organizm::pozycjaY-=2;
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
						Organizm::pozycjaY-=2;
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
						Organizm::pozycjaY-=2;
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
}

void Antylopa::RuchE()

{
	std::string thisNazwa = swiat.GetTypOrganizmu(this);

	int noweY = pozycjaY;
	int noweX = pozycjaX + 2;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	if (pozycjaY < swiat.GetSzerokosc()-1)
	{
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaX+=2;
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
					Organizm::pozycjaX+=2;
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
					Organizm::pozycjaX+=2;
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

void Antylopa::RuchS()

{
	int noweY = pozycjaY + 2;
	int noweX = pozycjaX;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	if (pozycjaY < swiat.GetWysokosc()-1)
	{

		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY+=2;
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
					Organizm::pozycjaY+=2;
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
					Organizm::pozycjaY+=2;
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

void Antylopa::RuchW()

{
	int noweY = pozycjaY;
	int noweX = pozycjaX - 2;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	if (pozycjaX > 2)
	{
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaX-=2;
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
					Organizm::pozycjaX-=2;
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
					Organizm::pozycjaX-=2;
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

void Antylopa::RuchNW()

{

	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	int noweY = pozycjaY - 2;
	int noweX = pozycjaX - 2;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	if (pozycjaY > 2 && pozycjaX > 2)
	{

		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY-=2;
			Organizm::pozycjaX-=2;
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
					Organizm::pozycjaY-=2;
					Organizm::pozycjaX-=2;
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
					Organizm::pozycjaY-=2;
					Organizm::pozycjaX-=2;
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

void Antylopa::RuchNE()

{

	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	int noweY = pozycjaY - 2;
	int noweX = pozycjaX + 2;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	if (pozycjaY > 2 && pozycjaX < swiat.GetSzerokosc()-1)
	{

		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY-=2;
			Organizm::pozycjaX+=2;
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
					Organizm::pozycjaY-=2;
					Organizm::pozycjaX+=2;
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
					Organizm::pozycjaY-=2;
					Organizm::pozycjaX+=2;
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

void Antylopa::RuchSE()

{

	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	int noweY = pozycjaY + 2;
	int noweX = pozycjaX + 2;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	if (pozycjaY < swiat.GetWysokosc() - 1 && pozycjaX < swiat.GetSzerokosc() - 1)
	{

		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY+=2;
			Organizm::pozycjaX+=2;
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
					Organizm::pozycjaY+=2;
					Organizm::pozycjaX+=2;
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
					Organizm::pozycjaY+=2;
					Organizm::pozycjaX+=2;
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

void Antylopa::RuchSW()

{
	int noweY = pozycjaY + 2;
	int noweX = pozycjaX - 2;
	int stareY = pozycjaY;
	int stareX = pozycjaX;
	std::string thisNazwa = swiat.GetTypOrganizmu(this);
	if (pozycjaY < swiat.GetWysokosc() - 1 && pozycjaX > 2)
	{

		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY+=2;
			Organizm::pozycjaX-=2;
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
					Organizm::pozycjaY+=2;
					Organizm::pozycjaX-=2;
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
					Organizm::pozycjaY+=2;
					Organizm::pozycjaX-=2;
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