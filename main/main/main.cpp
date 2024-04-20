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

	//organizmy.push_back(new Czlowiek(1, 1, swiat));
	//organizmy.push_back(new Wilk(4, 4, swiat));
	//organizmy.push_back(new Owca(3, 3, swiat));
	//organizmy.push_back(new Lis(2, 2, swiat));
	//organizmy.push_back(new Zolw(6, 6, swiat));
	organizmy.push_back(new Mlecz(20, 20, swiat));
	organizmy.push_back(new Trawa(9, 1, swiat));
	//organizmy.push_back(new Antylopa(5, 5, swiat));
	
	swiat.DorastanieStart();
	do
	{
		system("cls");
		swiat.Wypisz();
		swiat.NastępnaTura();

		system("cls");
		swiat.Wypisz();

		_getch();
		swiat.CzyscLog();
	} while (true);



	return 0;
}
