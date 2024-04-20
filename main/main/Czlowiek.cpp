#include "Czlowiek.h"
#include "Definicje.h"

#include "Rosliny.h"

#include <string>

Czlowiek::Czlowiek(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Zwierze(swiat)
{
	Organizm::sila = 5;
	Organizm::inicjatywa = 4;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
	this->zdolnosc = 10;
}

void Czlowiek::Akcja()
{
	CialoPalenie();

	int kierunek;
	Gotoxy(1, swiat.GetWysokosc() + 7);
	std::cout << "Wubierz kierunek, w krorym sie poruszysz: ";
	std::cin >> kierunek;
	std::string log = "";
	
	switch (kierunek)
	{
	case 8:
		RuchN();
		break;
	case 6:
		RuchE();
		break;
	case 2:
		RuchS();
		break;
	case 4:
		RuchW();
		break;
	case 7:
		RuchNW();
		break;
	case 9:
		RuchNE();
		break;
	case 3:
		RuchSE();
		break;
	case 1:
		RuchSW();
		break;
	case 5:
		if (zdolnosc == 10)
		{
			zdolnosc = 0;
			std::string log = "Czlowiek z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") uzywa zdolnosci. ";
			swiat.DodajLog(log);
			CialoPalenie();
		}
		else {
			std::string log =  "Czlowiek z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") zdolnosc sie laduje. \n";
			swiat.DodajLog(log);
		}
		break;
	default:
		break;
	}
	if (zdolnosc!=10)
	{
		zdolnosc++;
	}
	CialoPalenie();
}

void Czlowiek::Kolizja(Organizm* organizmy)
{
	int x = organizmy->GetPozycjaX();
	int y = organizmy->GetPozycjaY();
	int index = swiat.getIndexOrganizmu(x, y);
	swiat.UsunOrganizm(index);
}

void Czlowiek::Wypisz()
{
	Organizm::Wypisz();
	std::cout << 'C';
}

Czlowiek::~Czlowiek()
{
}

void Czlowiek::CialoPalenie()
{
	std::string log = "";
	if (zdolnosc < 6)
	{
		log = "Czlowiek z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") zdolnosc aktywna. ";
		swiat.DodajLog(log);
		if (swiat.OrganizmXY(pozycjaX, pozycjaY - 1))
		{
			Organizm* organizm = swiat.GetOrganizm(pozycjaX, pozycjaY - 1);
			std::string nazwa = swiat.GetTypOrganizmu(organizm);
			log = "Czlowiek z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
			swiat.DodajLog(log);
			Czlowiek::Kolizja(organizm);
		}
		if (swiat.OrganizmXY(pozycjaX, pozycjaY + 1))
		{
			Organizm* organizm = swiat.GetOrganizm(pozycjaX, pozycjaY + 1);
			std::string nazwa = swiat.GetTypOrganizmu(organizm);
			log = "Czlowiek z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
			swiat.DodajLog(log);
			Czlowiek::Kolizja(organizm);
		}
		if (swiat.OrganizmXY(pozycjaX - 1, pozycjaY - 1))
		{
			Organizm* organizm = swiat.GetOrganizm(pozycjaX - 1, pozycjaY - 1);
			std::string nazwa = swiat.GetTypOrganizmu(organizm);
			log = "Czlowiek z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
			swiat.DodajLog(log);
			Czlowiek::Kolizja(organizm);
		}
		if (swiat.OrganizmXY(pozycjaX + 1, pozycjaY - 1))
		{
			Organizm* organizm = swiat.GetOrganizm(pozycjaX + 1, pozycjaY - 1);
			std::string nazwa = swiat.GetTypOrganizmu(organizm);
			log = "Czlowiek z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
			swiat.DodajLog(log);
			Czlowiek::Kolizja(organizm);
		}
		if (swiat.OrganizmXY(pozycjaX - 1, pozycjaY + 1))
		{
			Organizm* organizm = swiat.GetOrganizm(pozycjaX - 1, pozycjaY + 1);
			std::string nazwa = swiat.GetTypOrganizmu(organizm);
			log = "Czlowiek z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
			swiat.DodajLog(log);
			Czlowiek::Kolizja(organizm);
		}
		if (swiat.OrganizmXY(pozycjaX + 1, pozycjaY + 1))
		{
			Organizm* organizm = swiat.GetOrganizm(pozycjaX + 1, pozycjaY + 1);
			std::string nazwa = swiat.GetTypOrganizmu(organizm);
			log = "Czlowiek z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
			swiat.DodajLog(log);
			Czlowiek::Kolizja(organizm);
		}
		if (swiat.OrganizmXY(pozycjaX + 1, pozycjaY))
		{
			Organizm* organizm = swiat.GetOrganizm(pozycjaX + 1, pozycjaY);
			std::string nazwa = swiat.GetTypOrganizmu(organizm);
			log = "Czlowiek z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
			swiat.DodajLog(log);
			Czlowiek::Kolizja(organizm);
		}
		if (swiat.OrganizmXY(pozycjaX - 1, pozycjaY))
		{
			Organizm* organizm = swiat.GetOrganizm(pozycjaX - 1, pozycjaY);
			std::string nazwa = swiat.GetTypOrganizmu(organizm);
			log = "Czlowiek z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
			swiat.DodajLog(log);
			Czlowiek::Kolizja(organizm);
		}
	}
}

void Czlowiek::RuchN()
{
	if (pozycjaY != 1)
	{
		int noweY = pozycjaY - 1;
		int noweX = pozycjaX;
		int stareY = pozycjaY;
		int stareX = pozycjaX;
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY--;
			std::string log = "Czlowiek z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
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
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					
					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					Organizm::pozycjaY--;
					swiat.DodajLog(log);
				}
				else {
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (this->sila >= przeciwnik->getSila())
				{
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaY--;
				}
				else {
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}
}

void Czlowiek::RuchE()
{
	if (pozycjaY != swiat.GetSzerokosc())
	{
		int noweY = pozycjaY;
		int noweX = pozycjaX + 1;
		int stareY = pozycjaY;
		int stareX = pozycjaX;
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaX++;
			std::string log = "Czlowiek z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
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
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					Organizm::pozycjaX++;
					swiat.DodajLog(log);
				}
				else {
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (this->sila >= przeciwnik->getSila())
				{
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaX++;
				}
				else {
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}

}

void Czlowiek::RuchS()
{
	if (pozycjaY != swiat.GetWysokosc())
	{
		int noweY = pozycjaY + 1;
		int noweX = pozycjaX;
		int stareY = pozycjaY;
		int stareX = pozycjaX;
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY++;
			std::string log = "Czlowiek z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
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
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					Organizm::pozycjaY++;
					swiat.DodajLog(log);
				}
				else {
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (this->sila >= przeciwnik->getSila())
				{
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaY++;
				}
				else {
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}

}

void Czlowiek::RuchW()
{
	if (pozycjaX != 1)
	{
		int noweY = pozycjaY;
		int noweX = pozycjaX - 1;
		int stareY = pozycjaY;
		int stareX = pozycjaX;
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaX--;
			std::string log = "Czlowiek z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
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
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{
					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					Organizm::pozycjaX--;
					swiat.DodajLog(log);
				}
				else {
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (this->sila >= przeciwnik->getSila())
				{
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaX--;
				}
				else {
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}
}

void Czlowiek::RuchNW()
{
	if (pozycjaY != 1 && pozycjaX != 1)
	{
		int noweY = pozycjaY - 1;
		int noweX = pozycjaX - 1;
		int stareY = pozycjaY;
		int stareX = pozycjaX;
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY--;
			Organizm::pozycjaX--;
			std::string log = "Czlowiek z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
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
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{

					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					Organizm::pozycjaY--;
					Organizm::pozycjaX--;
					swiat.DodajLog(log);
				}
				else {
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (this->sila >= przeciwnik->getSila())
				{
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaY--;
					Organizm::pozycjaX--;
				}
				else {
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}
}

void Czlowiek::RuchNE()
{
	if (pozycjaY != 1 && pozycjaX != swiat.GetSzerokosc())
	{
		int noweY = pozycjaY - 1;
		int noweX = pozycjaX + 1;
		int stareY = pozycjaY;
		int stareX = pozycjaX;
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY--;
			Organizm::pozycjaX++;
			std::string log = "Czlowiek z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
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
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{

					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					Organizm::pozycjaY--;
					Organizm::pozycjaX++;
					swiat.DodajLog(log);
				}
				else {
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (this->sila >= przeciwnik->getSila())
				{
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaY--;
					Organizm::pozycjaX++;
				}
				else {
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}

}

void Czlowiek::RuchSE()
{
	if (pozycjaY != 1 && pozycjaX != swiat.GetSzerokosc())
	{
		int noweY = pozycjaY + 1;
		int noweX = pozycjaX + 1;
		int stareY = pozycjaY;
		int stareX = pozycjaX;
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY++;
			Organizm::pozycjaX++;
			std::string log = "Czlowiek z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
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
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{

					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					Organizm::pozycjaY++;
					Organizm::pozycjaX++;
					swiat.DodajLog(log);
				}
				else {
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (this->sila >= przeciwnik->getSila())
				{
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaY++;
					Organizm::pozycjaX++;
				}
				else {
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}

}

void Czlowiek::RuchSW()
{
	if (pozycjaY != 1 && pozycjaX != swiat.GetSzerokosc())
	{
		int noweY = pozycjaY + 1;
		int noweX = pozycjaX - 1;
		int stareY = pozycjaY;
		int stareX = pozycjaX;
		if (!swiat.OrganizmXY(noweX, noweY))
		{
			Organizm::pozycjaY--;
			Organizm::pozycjaX++;
			std::string log = "Czlowiek z (" + std::to_string(stareX) + ", " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ").\n";
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
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
				else if (this->sila >= przeciwnik->getSila())
				{

					przeciwnik->Kolizja(this);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") niszczac " + nazwa + ".\n";
					Organizm::pozycjaY--;
					Organizm::pozycjaX++;
					swiat.DodajLog(log);
				}
				else {
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					przeciwnik->Kolizja(this);
				}
			}
			else if (dynamic_cast<Zwierze*>(przeciwnik))
			{
				if (this->sila >= przeciwnik->getSila())
				{
					std::string log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareX) + ") przeszedl  na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zabijajac  " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(przeciwnikX, przeciwnikY));
					Organizm::pozycjaY--;
					Organizm::pozycjaX++;
				}
				else {
					log = "Czlowiek z (" + std::to_string(stareX) + " " + std::to_string(stareY) + ") chcac przejsc na (" + std::to_string(noweX) + " " + std::to_string(noweY) + ") zostal zniszczony przez " + nazwa + ".\n";
					swiat.DodajLog(log);
					swiat.UsunOrganizm(swiat.getIndexOrganizmu(stareX, stareY));
				}
			}
		}
	}

}
