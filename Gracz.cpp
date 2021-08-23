#pragma once
#include "Gracz.h"
#include <vector>
#include "Kasyno.h"
#include <iostream>

Gracz::Gracz(std::vector<std::shared_ptr<Karta>> _rekav, std::string _imie, int _pkt, bool pas, bool bot)
{
	setImie(_imie);
	setPkt();
}

Gracz::Gracz()
{
}

void Gracz::setRekav(Karta karta)
{
	rekav.push_back(karta);
}

void Gracz::setImie(std::string _imie) {
	imie = _imie;
}

void Gracz::setPkt()
{
	pkt = 0;
	for (int i = 0; i < getIloscKart(); i++)
	{
		pkt = pkt + rekav.at(i).getWartosc();
	}
}

int Gracz::getPkt()
{
	setPkt();
	return pkt;
}

void Gracz::wyswietlKarty()
{
	for (int i = 0; i < rekav.size(); i++)
	{
		rekav.at(i).wypisz();
		std::cout << " ";
	}
}

std::string Gracz::drukujKarty()
{
	std::string karty;
	for (int i = 0; i < rekav.size(); i++)
	{
		karty.append(std::string(1, rekav.at(i).getFigura()));
		if (rekav.at(i).getKolor() == 3)
		{
			karty.append("[kier]");
		}
		else if (rekav.at(i).getKolor() == 4)
		{
			karty.append("[karo]");
		}
		else if (rekav.at(i).getKolor() == 5)
		{
			karty.append("[trefl]");
		}
		else if (rekav.at(i).getKolor() == 6)
		{
			karty.append("[pik]");
		}
		karty.append(" ");
	}
	return karty;
}

bool Gracz::getPas()
{
	if (pas == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Gracz::getBot()
{
	if (bot == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Gracz::setOdwaga(int _odwaga)
{
	odwaga = _odwaga;
}
