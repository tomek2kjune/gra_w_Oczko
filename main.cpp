#pragma once
#include <iostream>
#include "Karta.h"
#include "Kasyno.h"
#include "Gracz.h"
#include <conio.h>

int main()
{
	int nrTura = 0;
	char input;

	std::cout << "GRA W OCZKO\n\n";

	Kasyno stolik = Kasyno(); //przygotowanie gry...

	std::cin.ignore();
	system("CLS");
	
	while (stolik.graczePas() != true) //gra toczy sie tak dlugo az wszyscy spasuja...
	{
		nrTura++;
		for (int i = 0; i < stolik.iloscGraczy(); i++) //przebieg tury po wszystkich graczach...
		{
			if (stolik.getGracz(i).getPkt() > 20) //jesli gracz ma > 20 pkt to pasuje automatycznie...
			{
				stolik.graczPasuje(i);
			}
			if (stolik.getGracz(i).getPas() != true) //jesli gracz nie spasowal...
			{
				if (stolik.getGracz(i).getBot() != true) //jesli gracz nie jest botem to mozna sterowac jego zagraniem...
				{
					std::cout << "TURA " << nrTura << "\n\n";
					std::cout << "Do gry zasiada " << stolik.getGracz(i).getImie() << "\n\n";
					std::cout << stolik.getGracz(i).getImie() << " wcisnij Enter, aby kontynuowac...";
					std::cin.get();
					system("CLS");
					std::cout << "TURA " << nrTura << "\n\n";
					std::cout << "Gracz: " << stolik.getGracz(i).getImie() << "\n\n";
					std::cout << "Karty w rece: ";
					stolik.getGracz(i).wyswietlKarty();
					std::cout << "\n\n";
					std::cout << "Punkty: " << stolik.getGracz(i).getPkt() << "\n";
					while (true)
					{
						std::cout << "\nDOBIERAM (wprowadz [D])\n";
						std::cout << "PAS (wprowadz [P])\n";
						std::cin >> input;
						if (input == 'd' || input == 'D')
						{
							system("CLS");
							std::cout << "TURA " << nrTura << "\n\n";
							std::cout << "Gracz: " << stolik.getGracz(i).getImie() << "\n\n";
							stolik.kartaDlaGracza(i, stolik.dajKarte());
							std::cout << "Karty w rece: ";
							stolik.getGracz(i).wyswietlKarty();
							std::cout << "\n\n";
							std::cout << "Punkty: " << stolik.getGracz(i).getPkt() << "\n\n";
							break;
						}
						else if (input == 'p' || input == 'P')
						{
							stolik.graczPasuje(i);
							break;
						}
						else
						{
							std::cout << "Nie ma takiej akcji :/";
						}
					}
					std::cin.ignore();
				}
				else //jesli gracz jest botem to zachowuje sie w zaleznosci od posiadanej odwagi...
				{
					std::cout << "TURA " << nrTura << "\n\n";
					std::cout << "Do gry zasiada " << stolik.getGracz(i).getImie() << "\n\n";
					if (stolik.getGracz(i).getOdwaga() == 1)
					{
						if (stolik.getGracz(i).getPkt() < 16)
						{
							stolik.kartaDlaGracza(i, stolik.dajKarte());
						}
						else
						{
							stolik.graczPasuje(i);
						}
					}
					else if (stolik.getGracz(i).getOdwaga() == 2)
					{
						if (stolik.getGracz(i).getPkt() < 18)
						{
							stolik.kartaDlaGracza(i, stolik.dajKarte());
						}
						else
						{
							stolik.graczPasuje(i);
						}
					}
					else if (stolik.getGracz(i).getOdwaga() == 3)
					{
						if (stolik.getGracz(i).getPkt() < 20)
						{
							stolik.kartaDlaGracza(i, stolik.dajKarte());
						}
						else
						{
							stolik.graczPasuje(i);
						}
					}
					std::cout << stolik.getGracz(i).getImie() << " rozegral ture" "\n\n";
				}
				std::cout << stolik.getGracz(i).getImie() << " wcisnij Enter, aby kontynuowac...";
				std::cin.get();
				system("CLS");
			}
		}
	}
	std::cout << "KONIEC GRY\n";
	std::cout << "TABELA WYNIKOW\n\n";
	if (stolik.graczeWygrana() == true) //jesli ktokolwiek uzbieral 21 pkt...
	{
		for (int i = 0; i < stolik.iloscGraczy(); i++)
		{
			std::cout.width(20);
			std::cout << stolik.getGracz(i).getImie() << ": ";
			std::cout << stolik.getGracz(i).getPkt() << " pkt	";
			stolik.getGracz(i).wyswietlKarty();
			if (stolik.getGracz(i).getPkt() == 21) //jesli gracz posiada 21 pkt to wygral
			{
				std::cout << "WYGRANA\n";
			}
			else //jesli gracz posiada +/- 21 pkt to przegrywa
			{
				std::cout << "PRZEGRANA\n";
			}
		}
	}
	else //jesli nikt nie uzbieral 21 pkt...
	{
		for (int i = 0; i < stolik.iloscGraczy(); i++)
		{
			std::cout.width(20);
			std::cout << stolik.getGracz(i).getImie() << ": ";
			std::cout << stolik.getGracz(i).getPkt() << " pkt	";
			stolik.getGracz(i).wyswietlKarty();
			if (stolik.getGracz(i).getPkt() > 21) //ten kto posiada > 21 pkt przegrywa
			{
				std::cout << "PRZEGRANA\n";
			}
			else if (stolik.getGracz(i).getPkt() == stolik.getMaxPkt()) //ten kto ma najwiecej i mniej niz 21 pkt to wygrywa
			{
				std::cout << "WYGRANA\n";
			}
			else //ten kto ma mniej pkt niz wygrany przegrywa
			{
				std::cout << "PRZEGRANA\n";
			}
		}
	}
	stolik.exportWyniki(); //export wynikow do pliku
	return 0;
}