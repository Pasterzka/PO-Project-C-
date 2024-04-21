#include <iostream>
#include <conio.h>

#include "Swiat.h"

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

int main()
{
	std::vector<Organizm*> organizmy;
	int szerokosc=0, wysokosc=0;

	int i = 0, wybor, x, y;
	bool out = true, out2 = true;

	int wyborgra;
	std::cout << "Witaj w grze stworzonej przez Jakub Pastuszka 199839 \n\n";
	std::cout << "Co chcesz zrobi?\n";
	std::cout << "1-nowa Gra, 2-wczytaj gre: ";
	std::cin >> wyborgra;
	Swiat swiat(szerokosc, wysokosc, &organizmy);
	switch (wyborgra)
	{
	case 1:
		std::cout << "Wczytaj szerokosc planszy: ";
		std::cin >> szerokosc;
		swiat.SetSzerokosc(szerokosc);

		std::cout << "Wczytaj wysokosc planszy: ";
		std::cin >> wysokosc;
		swiat.SetWysokosc(wysokosc);

		std::cout << "Plansza stworzona!";
		_getch();

		system("cls");

		while (out2)
		{
			x = rand() % szerokosc + 1;
			y = rand() % wysokosc + 1;
			if (!swiat.OrganizmXY(x, y))
			{
				out2 = false;
				swiat.DodajOrganizm(new Czlowiek(x, y, swiat));
				std::cout << "Dodano Czlowiek na (" << x << " " << y << ").\n";
			}
		}
		i++;
		while (out && i != wysokosc * szerokosc)
		{
			std::cout << "Dodaj organizmy do gry.\n";
			std::cout << "1-Antylopa, 2-Lis, 3-Owca, 4-Wilk, 5-Zolw, 6-BarszczSosnowksiegp, 7-Guarana, 8-Mlecz, 9-Trawa, 10-WilczeJagody, 11-idz dalej\n";
			std::cin >> wybor;
			out2 = true;
			switch (wybor)
			{
			case 1:
				while (out2)
				{
					x = rand() % szerokosc + 1;
					y = rand() % wysokosc + 1;
					if (!swiat.OrganizmXY(x, y))
					{
						out2 = false;
						swiat.DodajOrganizm(new Antylopa(x, y, swiat));
						std::cout << "Dodano Antylope na (" << x << " " << y << ").\n";
					}
				}

				i++;
				break;
			case 2:
				while (out2)
				{
					x = rand() % szerokosc + 1;
					y = rand() % wysokosc + 1;
					if (!swiat.OrganizmXY(x, y))
					{
						out2 = false;
						swiat.DodajOrganizm(new Lis(x, y, swiat));
						std::cout << "Dodano Lis na (" << x << " " << y << ").\n";
					}
				}

				i++;
				break;
			case 3:
				while (out2)
				{
					x = rand() % szerokosc + 1;
					y = rand() % wysokosc + 1;
					if (!swiat.OrganizmXY(x, y))
					{
						out2 = false;
						swiat.DodajOrganizm(new Owca(x, y, swiat));
						std::cout << "Dodano Owca na (" << x << " " << y << ").\n";
					}
				}

				i++;
				break;
			case 4:
				while (out2)
				{
					x = rand() % szerokosc + 1;
					y = rand() % wysokosc + 1;
					if (!swiat.OrganizmXY(x, y))
					{
						out2 = false;
						swiat.DodajOrganizm(new Wilk(x, y, swiat));
						std::cout << "Dodano Wilk na (" << x << " " << y << ").\n";
					}
				}

				i++;
				break;
			case 5:
				while (out2)
				{
					x = rand() % szerokosc + 1;
					y = rand() % wysokosc + 1;
					if (!swiat.OrganizmXY(x, y))
					{
						out2 = false;
						swiat.DodajOrganizm(new Zolw(x, y, swiat));
						std::cout << "Dodano Zolw na (" << x << " " << y << ").\n";
					}
				}

				i++;
				break;
			case 6:
				while (out2)
				{
					x = rand() % szerokosc + 1;
					y = rand() % wysokosc + 1;
					if (!swiat.OrganizmXY(x, y))
					{
						out2 = false;
						swiat.DodajOrganizm(new BarszczSosnowskiego(x, y, swiat));
						std::cout << "Dodano Barszcz Sosnowkiego na (" << x << " " << y << ").\n";
					}
				}

				i++;
				break;
			case 7:
				while (out2)
				{
					x = rand() % szerokosc + 1;
					y = rand() % wysokosc + 1;
					if (!swiat.OrganizmXY(x, y))
					{
						out2 = false;
						swiat.DodajOrganizm(new Guarana(x, y, swiat));
						std::cout << "Dodano Guarana na (" << x << " " << y << ").\n";
					}
				}

				i++;
				break;
			case 8:
				while (out2)
				{
					x = rand() % szerokosc + 1;
					y = rand() % wysokosc + 1;
					if (!swiat.OrganizmXY(x, y))
					{
						out2 = false;
						swiat.DodajOrganizm(new Mlecz(x, y, swiat));
						std::cout << "Dodano Mlecz na (" << x << " " << y << ").\n";
					}
				}

				i++;
				break;
			case 9:
				while (out2)
				{
					x = rand() % szerokosc + 1;
					y = rand() % wysokosc + 1;
					if (!swiat.OrganizmXY(x, y))
					{
						out2 = false;
						swiat.DodajOrganizm(new Trawa(x, y, swiat));
						std::cout << "Dodano Trawa na (" << x << " " << y << ").\n";
					}
				}

				i++;
				break;
			case 10:
				while (out2)
				{
					x = rand() % szerokosc + 1;
					y = rand() % wysokosc + 1;
					if (!swiat.OrganizmXY(x, y))
					{
						out2 = false;
						swiat.DodajOrganizm(new WilczeJagody(x, y, swiat));
						std::cout << "Dodano Wilcze Jagody na (" << x << " " << y << ").\n";
					}
				}

				i++;
				break;
			case 11:
				out = false;
				break;
			default:
				break;
			}
		}

		std::cout << "Gra gotowa! Wciśnij dowolny klawisz!";
		_getch();
		swiat.DorastanieStart();
		break;
		case 2:
			swiat.Wczytaj();
			break;
	default:
		break;
	}
	
	//organizmy.push_back(new Wilk(3, 4, swiat));
	//organizmy.push_back(new Wilk(4, 4, swiat));
	//organizmy.push_back(new Lis(2, 2, swiat));
	//organizmy.push_back(new Zolw(1, 2, swiat));
	//organizmy.push_back(new Trawa(2, 2, swiat));
	//organizmy.push_back(new Trawa(1, 2, swiat));
	//organizmy.push_back(new WilczeJagody(1, 1, swiat));
	//organizmy.push_back(new Mlecz(20, 20, swiat));
	//organizmy.push_back(new BarszczSosnowskiego(1, 1, swiat)); 
	//organizmy.push_back(new Owca(5, 6, swiat));
	//organizmy.push_back(new Owca(8, 6, swiat));
	//organizmy.push_back(new Antylopa(2, 3, swiat));

	bool gra = true;
	int wybor6;
	do
	{
		system("cls");
		swiat.Wypisz();
		
		swiat.NastępnaTura();

		system("cls");
		swiat.Wypisz();
		swiat.GetLogi();
		std::cout << "\n\nCo chcesz zrobic?\n";
		std::cout << "1-nastepna tura, 2-zapisz, 3-wyjdz: ";
		std::cin >> wybor6;
		switch (wybor6)
		{
		case 1:
			break;
		case 2:
			swiat.Zapisz();
			gra = false;
			break;
		case 3:
			gra = false;
			break;
		default:
			break;
		}

		swiat.CzyscLog();
	} while (gra);
	

	
	/*if (dynamic_cast<Mlecz*>(organizmy[0]))
	{
		std::cout << "MLECZ";
	}
	else {
		std::cout << "NIE MLECZ";
	}*/
	
	return 0;
}
