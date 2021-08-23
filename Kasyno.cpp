#pragma once
#include "Kasyno.h"
#include <algorithm>
#include <random>
#include <iostream>
#include <fstream>  
#include "Gracz.h"
#include <string>
#include <sstream>

void Kasyno::talia()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			Karta nowa = Karta(i, j);
			taliav.push_back (nowa);
		}
	}
}

void Kasyno::tasuj()
{
	std::random_device rd;
	std::default_random_engine rng(rd());
	std::shuffle(taliav.begin(), taliav.end(), rng);
}

Karta Kasyno::dajKarte() 
{
	Karta pierwsza;
	pierwsza = taliav.back();
	taliav.pop_back();
	return pierwsza;
}

void Kasyno::dodajGracza()
{
	Gracz nowy = Gracz();
	
	std::cout << "Podaj imie gracza: ";
	std::string imie;
	std::cin >> imie;
	if (imie.length() > 20)
	{
		imie.erase(imie.begin() + 20, imie.end());
	}
	nowy.setImie(imie);
	graczev.push_back(nowy);
}

void Kasyno::dodajBota(int _index)
{
	Gracz nowy = Gracz();
	std::string imie = "Bot";

	nowy.setBot();
	imie.append(std::to_string(_index));
	nowy.setImie(imie);
	graczev.push_back(nowy);
}

void Kasyno::stworzGraczy()
{
	std::string ilegs, ilebs, odwagas;
	int ileg, ileb, index = 1, odwaga;
	std::cout << "Podaj liczbe graczy (od 1 do 3): ";
	std::cin >> ilegs;
	std::istringstream(ilegs) >> ileg;
	if (ileg < 1)
	{
		ileg = 1;
	}
	else if (ileg > 3)
	{
		ileg = 3;
	}
	for (int i = 0; i < ileg; i++)
	{
		dodajGracza();
		kartaDlaGracza(i, dajKarte());
		kartaDlaGracza(i, dajKarte());
	}

	std::cout << "\nPodaj liczbe graczy komputerowych (od 1 do 3): ";
	std::cin >> ilebs;
	std::istringstream(ilebs) >> ileb;
	if (ileb < 1)
	{
		ileb = 1;
	}
	else if (ileb > 3)
	{
		ileb = 3;
	}
	ileb = ileb + ileg;
	for (int i = ileg; i < ileb; i++)
	{
		dodajBota(index);
		std::cout << "Okresl odwage Bota" << index << " (od 1 do 3)" << ": ";
		std::cin >> odwagas;
		std::istringstream(odwagas) >> odwaga;
		if (odwaga < 1)
		{
			odwaga = 1;
		}
		else if (odwaga > 3)
		{
			odwaga = 3;
		}
		graczev.at(i).setOdwaga(odwaga);
		kartaDlaGracza(i, dajKarte());
		kartaDlaGracza(i, dajKarte());
		index++;
	}
}

void Kasyno::kartaDlaGracza(int _index, Karta _karta)
{
	graczev.at(_index).setRekav(_karta);
}

void Kasyno::graczPasuje(int _index)
{
	graczev.at(_index).setPas();
}

bool Kasyno::graczePas()
{
	for (int i = 0; i < iloscGraczy(); i++)
	{
		if (getGracz(i).getPas() != true)
		{
			return false;
		}
	}
	return true;
}

bool Kasyno::graczeWygrana()
{
	for (int i = 0; i < iloscGraczy(); i++)
	{
		if (graczev.at(i).getPkt() == 21)
		{
			return true;
		}
	}
	return false;
}

int Kasyno::getMaxPkt()
{
	for (int i = 0; i < iloscGraczy(); i++)
	{
		if (graczev.at(i).getPkt() > maxPkt && graczev.at(i).getPkt() < 21)
		{
			maxPkt = graczev.at(i).getPkt();
		}
	}
	return maxPkt;
}

void Kasyno::exportWyniki()
{
	std::ofstream raport("raport.txt");

	if (graczeWygrana() == true)
	{
		for (int i = 0; i < iloscGraczy(); i++)
		{
			raport.width(20);
			raport << getGracz(i).getImie() << ": ";
			raport << getGracz(i).getPkt() << " pkt		";
			raport << getGracz(i).drukujKarty();
			if (getGracz(i).getPkt() == 21)
			{
				raport << " WYGRANA\n";
			}
			else
			{
				raport << " PRZEGRANA\n";
			}
		}
	}
	else
	{
		for (int i = 0; i < iloscGraczy(); i++)
		{
			raport.width(20);
			raport << getGracz(i).getImie() << ": ";
			raport << getGracz(i).getPkt() << " pkt		";
			raport << getGracz(i).drukujKarty();
			if (getGracz(i).getPkt() > 21)
			{
				raport << " PRZEGRANA\n";
			}
			else if (getGracz(i).getPkt() == getMaxPkt())
			{
				raport << " WYGRANA\n";
			}
			else
			{
				raport << " PRZEGRANA\n";
			}
		}
	}

	raport.close();
}