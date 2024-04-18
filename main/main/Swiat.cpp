#include "Swiat.h"

Swiat::Swiat(unsigned wysokosc, unsigned szerokosc, std::vector<Organizm*>* organizmy)
	:wysokosc(wysokosc), szerokosc(szerokosc), organizmy(organizmy)
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

	for (int i = 0; i < organizmy->size(); i++)
	{
		(*organizmy)[i]->Akcja();
	}
}

void Swiat::Wypisz()
{
	std::cout << "Jakub Pastuska 198339";
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
}

Swiat::~Swiat()
{
}
