#include "Swiat.h"
#include <conio.h>
#include <algorithm>
#include "Funkcje.h"


#include "Czlowiek.h"
#include "Owca.h"
#include "Wilk.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"

#include "Trawa.h"
#include "Mlecz.h"
#include "WilczeJagody.h"
#include "Guarana.h"
#include "BarszczSosnowskiegp.h"

Swiat::Swiat(unsigned wysokosc, unsigned szerokosc, std::vector<Organizm*>* organizmy)
	:wysokosc(wysokosc), szerokosc(szerokosc), organizmy(organizmy), tura(1)
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
	std::sort(organizmy->begin(), organizmy->end(), [](Organizm* a, Organizm* b) {
		return a->getInicjatywa() > b->getInicjatywa(); });
	for (this->globalIndexl = 0; this->globalIndexl < organizmy->size(); this->globalIndexl++)
	{
		if ((*organizmy)[this->globalIndexl]->getWiek()>0)
		{
			(*organizmy)[this->globalIndexl]->Akcja();
		}
		(*organizmy)[this->globalIndexl]->Dorastanie();
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

void Swiat::GetLogi()
{
	Gotoxy(1, wysokosc + 9);
	std::cout << "Logi z aktualnej tury:" << tura - 1;
	Gotoxy(1, wysokosc + 10);
	std::cout << this->log;
}

int Swiat::getIndexOrganizmu(int x, int y)
{
	for (int i = 0; i < organizmy->size(); i++)
	{
		(*organizmy)[i]->Dorastanie();
		if ((*organizmy)[i]->GetPozycjaX() == x && (*organizmy)[i]->GetPozycjaY() == y)
		{
			return i;
		}
	}
}

void Swiat::UsunOrganizm(int index)
{
	//// SprawdŸ, czy index jest poprawny
	//if (index >= 0 && static_cast<size_t>(index) < organizmy->size()) {
	//	// Usuñ element ze wskazanego indeksu
	//	delete (*organizmy)[index]; // Zwolnienie pamiêci zaalokowanej na obiekt
	//	organizmy->erase(organizmy->begin() + index); // Usuniêcie wskaŸnika z wektora
	//}
	if (this->globalIndexl>index)
	{
		this->globalIndexl--;
	}
	(*organizmy)[index]->SetInicjatywa(-1);
	std::sort(organizmy->begin(), organizmy->end(), [](Organizm* a, Organizm* b) {
		return a->getInicjatywa() > b->getInicjatywa(); });
	organizmy->pop_back();
}

Organizm* Swiat::GetOrganizm(int x, int y)
{
	for (Organizm*& organizm : *organizmy)
	{
		if (organizm->GetPozycjaX() == x && organizm->GetPozycjaY() == y)
		{
			return organizm;
		}
	}
}

std::string Swiat::GetTypOrganizmu(Organizm* organizm)
{
	if (dynamic_cast<Czlowiek*>(organizm))
	{
		return "Czlowiek";
	}
	else if (dynamic_cast<Antylopa*>(organizm))
	{
		return "Antylopa";
	}
	else if (dynamic_cast<Lis*>(organizm))
	{
		return "Lis";
	}
	else if (dynamic_cast<Owca*>(organizm))
	{
		return "Owca";
	}
	else if (dynamic_cast<Wilk*>(organizm))
	{
		return "Wilk";
	}
	else if (dynamic_cast<Zolw*>(organizm))
	{
		return "Zolw";
	}
	else if (dynamic_cast<BarszczSosnowskiego*>(organizm))
	{
		return "Barszcz Sosnowskiego";
	}
	else if (dynamic_cast<Guarana*>(organizm))
	{
		return "Guarana";
	}
	else if (dynamic_cast<Mlecz*>(organizm))
	{
		return "Mlecz";
	}
	else if (dynamic_cast<Trawa*>(organizm))
	{
		return "Trawa";
	}
	else if (dynamic_cast<WilczeJagody*>(organizm))
	{
		return "Wilcze Jagody";
	}
}

int Swiat::GetDlougoscOrganizmow()
{
	return organizmy->size();
}

bool Swiat::CzyOdbil(Organizm* organizm)
{
	if (organizm->getSila()<5)
	{
		return true;
	}
	return false;
}

bool Swiat::CzyKolizja(Organizm* organizm1, Organizm* organizm2)
{
	std::string nazwa1 = this->GetTypOrganizmu(organizm1);
	std::string nazwa2 = this->GetTypOrganizmu(organizm2);
	if (nazwa1 == nazwa2)
	{
		return true;
	}
	return false;
}

Swiat::~Swiat()
{
}
