#include "BarszczSosnowskiegp.h"

#include <string>

BarszczSosnowskiego::BarszczSosnowskiego(int pozycjaX, int pozycjaY, Swiat& swiat)
	:Roslina(swiat)
{
	Organizm::sila = 10;
	Organizm::inicjatywa = 0;
	Organizm::pozycjaX = pozycjaX;
	Organizm::pozycjaY = pozycjaY;
	Organizm::swiat = swiat;
}

void BarszczSosnowskiego::Akcja()
{
	Zdolnosc();
	Roslina::Akcja();
}

void BarszczSosnowskiego::Kolizja(Organizm* organizmy)
{
	int x = organizmy->GetPozycjaX();
	int y = organizmy->GetPozycjaY();
	int index = swiat.getIndexOrganizmu(x, y);
	swiat.UsunOrganizm(index);
}

void BarszczSosnowskiego::Wypisz()
{
	Organizm::Wypisz();
	std::cout << "B";
}

void BarszczSosnowskiego::Zdolnosc()
{

	std::string log;
	log = "Barszcz Sosnowskiego z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") aktywuje Kolizja(Organizm* organizm). ";
	swiat.DodajLog(log);
	if (swiat.OrganizmXY(pozycjaX, pozycjaY - 1) && !dynamic_cast<BarszczSosnowskiego*>(swiat.GetOrganizm(pozycjaX, pozycjaY - 1)))
	{
		Organizm* organizm = swiat.GetOrganizm(pozycjaX, pozycjaY - 1);
		std::string nazwa = swiat.GetTypOrganizmu(organizm);
		log = "Barszcz Sosnowskiego z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
		swiat.DodajLog(log);

		BarszczSosnowskiego::Kolizja(organizm);
	}
	if (swiat.OrganizmXY(pozycjaX, pozycjaY + 1) && !dynamic_cast<BarszczSosnowskiego*>(swiat.GetOrganizm(pozycjaX, pozycjaY + 1)))
	{
		Organizm* organizm = swiat.GetOrganizm(pozycjaX, pozycjaY + 1);
		std::string nazwa = swiat.GetTypOrganizmu(organizm);
		log = "Barszcz Sosnowskiego z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
		swiat.DodajLog(log);

		BarszczSosnowskiego::Kolizja(organizm);
	}
	if (swiat.OrganizmXY(pozycjaX - 1, pozycjaY - 1) && !dynamic_cast<BarszczSosnowskiego*>(swiat.GetOrganizm(pozycjaX - 1, pozycjaY - 1)))
	{
		Organizm* organizm = swiat.GetOrganizm(pozycjaX - 1, pozycjaY - 1);
		std::string nazwa = swiat.GetTypOrganizmu(organizm);
		log = "Barszcz Sosnowskiego z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
		swiat.DodajLog(log);

		BarszczSosnowskiego::Kolizja(organizm);
	}
	if (swiat.OrganizmXY(pozycjaX + 1, pozycjaY - 1) && !dynamic_cast<BarszczSosnowskiego*>(swiat.GetOrganizm(pozycjaX + 1, pozycjaY - 1)))
	{
		Organizm* organizm = swiat.GetOrganizm(pozycjaX + 1, pozycjaY - 1);
		std::string nazwa = swiat.GetTypOrganizmu(organizm);
		log = "Barszcz Sosnowskiego z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
		swiat.DodajLog(log);

		BarszczSosnowskiego::Kolizja(organizm);
	}
	if (swiat.OrganizmXY(pozycjaX - 1, pozycjaY + 1) && !dynamic_cast<BarszczSosnowskiego*>(swiat.GetOrganizm(pozycjaX - 1, pozycjaY + 1)))
	{
		Organizm* organizm = swiat.GetOrganizm(pozycjaX - 1, pozycjaY + 1);
		std::string nazwa = swiat.GetTypOrganizmu(organizm);
		log = "Barszcz Sosnowskiego z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
		swiat.DodajLog(log);

		BarszczSosnowskiego::Kolizja(organizm);
	}
	if (swiat.OrganizmXY(pozycjaX + 1, pozycjaY + 1) && !dynamic_cast<BarszczSosnowskiego*>(swiat.GetOrganizm(pozycjaX + 1, pozycjaY + 1)))
	{
		Organizm* organizm = swiat.GetOrganizm(pozycjaX + 1, pozycjaY + 1);
		std::string nazwa = swiat.GetTypOrganizmu(organizm);
		log = "Barszcz Sosnowskiego z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
		swiat.DodajLog(log);

		BarszczSosnowskiego::Kolizja(organizm);
	}
	if (swiat.OrganizmXY(pozycjaX-1, pozycjaY) && !dynamic_cast<BarszczSosnowskiego*>(swiat.GetOrganizm(pozycjaX - 1, pozycjaY)))
	{
		Organizm* organizm = swiat.GetOrganizm(pozycjaX - 1, pozycjaY);
		std::string nazwa = swiat.GetTypOrganizmu(organizm);
		log = "Barszcz Sosnowskiego z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
		swiat.DodajLog(log);

		BarszczSosnowskiego::Kolizja(organizm);
	}
	if (swiat.OrganizmXY(pozycjaX + 1, pozycjaY) && !dynamic_cast<BarszczSosnowskiego*>(swiat.GetOrganizm(pozycjaX + 1, pozycjaY)))
	{
		Organizm* organizm = swiat.GetOrganizm(pozycjaX + 1, pozycjaY);
		std::string nazwa = swiat.GetTypOrganizmu(organizm);
		log = "Barszcz Sosnowskiego z (" + std::to_string(pozycjaX) + " " + std::to_string(pozycjaY) + ") spala " + nazwa + ". ";
		swiat.DodajLog(log);

		BarszczSosnowskiego::Kolizja(organizm);
	}
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}
