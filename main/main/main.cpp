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

	Swiat swiat( 20, 20, &organizmy);
	//organizmy.push_back(new Owca(3, 3, swiat));
	//organizmy.push_back(new Lis(2, 2, swiat));
	//organizmy.push_back(new Zolw(6, 6, swiat));
	organizmy.push_back(new Trawa(2, 1, swiat));
	organizmy.push_back(new WilczeJagody(1, 1, swiat));
	organizmy.push_back(new Mlecz(20, 20, swiat));
	organizmy.push_back(new Czlowiek(3, 2, swiat));
	//organizmy.push_back(new Wilk(1, 1, swiat));
	//organizmy.push_back(new Antylopa(1, 1, swiat));
	//organizmy.push_back(new BarszczSosnowskiego(1, 1, swiat));

	swiat.DorastanieStart();
	do
	{
		system("cls");
		swiat.Wypisz();
		swiat.NastępnaTura();

		system("cls");
		swiat.Wypisz();
		swiat.GetLogi();
		_getch();
		swiat.CzyscLog();
	} while (true);
	

	
	/*if (dynamic_cast<Mlecz*>(organizmy[0]))
	{
		std::cout << "MLECZ";
	}
	else {
		std::cout << "NIE MLECZ";
	}*/
	
	return 0;
}
