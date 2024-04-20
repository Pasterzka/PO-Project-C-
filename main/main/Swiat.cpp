#include "Swiat.h"
#include <conio.h>

Swiat::Swiat(unsigned wysokosc, unsigned szerokosc, std::vector<Organizm*>* organizmy)
	:wysokosc(wysokosc), szerokosc(szerokosc), organizmy(organizmy), tura(0)
{
}

void Swiat::DodajOrganizm(Organizm* organizm)
{
	this->organizmy->push_back(organizm);
}

unsigned Swiat::GetWysokosc() const
{
	return wysokosc;
}

unsigned Swiat::GetSzerokosc() const
{
	return szerokosc;
}



void Swiat::NastêpnaTura()
{
	tura++;

	for (int i = 0; i < organizmy->size(); i++)
	{
		if ((*organizmy)[i]->getWiek()>0)
		{
			(*organizmy)[i]->Akcja();
		}
		(*organizmy)[i]->Dorastanie();
	}
}

void Swiat::Wypisz()
{
	std::cout << "Jakub Pastuska 198339";
	Gotoxy(1, 2);
	std::cout << "Tura: " << tura;
	Gotoxy(1, 3);
	for (int i = 0; i < szerokosc+2; i++)
	{
		std::cout << 'x';
	}
	Gotoxy(1, 3);
	for (int i = 0; i < wysokosc + 2; i++)
	{
		std::cout << 'x' << std::endl;
	}
	Gotoxy(1, 3+wysokosc+1);
	for (int i = 0; i < szerokosc + 2; i++)
	{
		std::cout << 'x';
	}
	for (int i = 0; i < wysokosc+2; i++)
	{
		Gotoxy(szerokosc+2, 3+i);
		std::cout << 'x';

	}
	
	for (Organizm*& organizm : *organizmy)
	{
		organizm->Wypisz();
	}

	Gotoxy(1, wysokosc + 9);
	std::cout << "Logi z aktualnej tury";
	Gotoxy(1, wysokosc + 10);
	std::cout << this->log;
}

bool Swiat::OrganizmXY(int x, int y)
{
	for (Organizm*& organizm : *organizmy)
	{
		if (organizm->GetPozycjaX() == x && organizm->GetPozycjaY() == y)
		{
			return true;
		}
	}
	return false;
}

void Swiat::CzyscLog()
{
	this->log = "";
}

void Swiat::DodajLog(std::string log)
{
	this->log += log;
}

void Swiat::DorastanieStart()
{
	for (int i = 0; i < organizmy->size(); i++)
	{
		(*organizmy)[i]->Dorastanie();
	}
}

Swiat::~Swiat()
{
}
