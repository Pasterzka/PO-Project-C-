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

Swiat::Swiat(unsigned wysokosc, unsigned szerokosc, std::vector<Organizm*>* organizmy, int tura)
	:wysokosc(wysokosc), szerokosc(szerokosc), organizmy(organizmy), tura(tura)
{
}

void Swiat::DodajOrganizm(Organizm* organizm)
{
	this->organizmy->push_back(organizm);
	std::sort(organizmy->begin(), organizmy->end(), [](Organizm* a, Organizm* b) {
		return a->getInicjatywa() > b->getInicjatywa(); });
	if (organizm->getInicjatywa()>(*organizmy)[globalIndexl]->getInicjatywa())
	{
		globalIndexl++;
	}
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

#include <fstream>

void Swiat::Zapisz()
{
	std::ofstream plik_out("zapis.txt");
	if (plik_out.is_open()) {
		plik_out << wysokosc << std::endl;
		plik_out << szerokosc << std::endl;
		plik_out << tura << std::endl;
		plik_out << this->GetDlougoscOrganizmow() << std::endl;
		for (Organizm*& organizm : *organizmy)
		{
			plik_out << this->GetTypOrganizmu(organizm) << " " << organizm->getInicjatywa() << " " << organizm->getSila() << " " << organizm->GetPozycjaX() << " " << organizm->GetPozycjaY() << " " << organizm->getWiek() << std::endl;
		}
		std::cout << "Gra zosta³ zapisany do pliku." << std::endl;
	}
	else {
		std::cout << "Nie mo¿na otworzyæ pliku do zapisu!" << std::endl;
	}
}

void Swiat::Wczytaj()
{
	std::ifstream plik_in("zapis.txt");
	int liczba, inicjatywa, sila, x, y, wiek;
	std::string nazwa;
	if (plik_in.is_open()) {
		
		plik_in >> wysokosc;
		plik_in >> szerokosc;
		plik_in >> tura;
		log = "";
		plik_in >> liczba;
		for (int i = 0; i < liczba; i++)
		{
			plik_in >> nazwa;
			plik_in >> inicjatywa;
			plik_in >> sila;
			plik_in >> x;
			plik_in >> y;
			plik_in >> wiek;
			
			this->wczytajOrganizm(nazwa, inicjatywa, sila, x, y, wiek);
		}


		std::cout << "Gra zosta³ odczytany z pliku." << std::endl;
	}
	else {
		std::cout << "Nie mo¿na otworzyæ pliku do odczytu!" << std::endl;
	}
}

void Swiat::wczytajOrganizm(std::string nazwa, int inicjatywa, int sila, int x, int y, int wiek)
{
	if (nazwa=="Czlowiek")
	{
		this->organizmy->push_back(new Czlowiek( inicjatywa, sila, x, y, wiek, *this));
	}
	else if (nazwa=="Antylopa")
	{
		this->organizmy->push_back(new Antylopa(inicjatywa, sila, x, y, wiek, *this));
	}
	else if (nazwa=="Lis")
	{
		this->organizmy->push_back(new Lis(inicjatywa, sila, x, y, wiek, *this));
	}
	else if (nazwa == "Owca")
	{
		this->organizmy->push_back(new Owca(inicjatywa, sila, x, y, wiek, *this));
	}
	else if (nazwa == "Wilk")
	{
		this->organizmy->push_back(new Wilk(inicjatywa, sila, x, y, wiek, *this));
	}
	else if (nazwa == "Zolw")
	{
		this->organizmy->push_back(new Zolw(inicjatywa, sila, x, y, wiek, *this));
	}
	else if (nazwa == "Barszcz Sosnowskiego")
	{
		this->organizmy->push_back(new BarszczSosnowskiego(inicjatywa, sila, x, y, wiek, *this));
	}
	else if (nazwa == "Trawa")
	{
		this->organizmy->push_back(new Trawa(inicjatywa, sila, x, y, wiek, *this));
	}
	else if (nazwa == "Mlecz")
	{
		this->organizmy->push_back(new Mlecz(inicjatywa, sila, x, y, wiek, *this));
	}
	else if (nazwa == "Guarana")
	{
		this->organizmy->push_back(new Guarana(inicjatywa, sila, x, y, wiek, *this));
	}
	else if (nazwa == "Wilcze Jagody")
	{
		this->organizmy->push_back(new WilczeJagody(inicjatywa, sila, x, y, wiek, *this));
	}
	
}

void Swiat::SetSzerokosc(int szerokosc)
{
	this->szerokosc = szerokosc;
}

void Swiat::SetWysokosc(int wysokosc)
{
	this->wysokosc = wysokosc;
}


Swiat::~Swiat()
{
}
