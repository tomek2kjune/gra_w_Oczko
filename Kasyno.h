#pragma once
#include <iostream>
#include "Karta.h"
#include "Gracz.h"
#include <vector>

class Kasyno {
private:
	std::vector<Karta> taliav; //talia kart
	std::vector<Gracz> graczev; //gracze
	int maxPkt = 0; 
public:
	Kasyno() //tworzy nowa gre
	{ 
		talia();
		tasuj();
		stworzGraczy();
	}
	void talia(); //tworzy talie
	void tasuj(); //tasuje talie
	Karta dajKarte(); //daje karte z tali
	void dodajGracza(); //dodaje gracza
	void stworzGraczy(); //tworzy wszystkich graczy
	Gracz getGracz(int _index) { return graczev.at(_index); }; //zwraca gracza
	void kartaDlaGracza(int _index, Karta _karta); //daje karte dla gracza
	bool graczePas(); //sprawdza czy wszyscy pas
	int iloscGraczy() { return graczev.size(); }; //zwraca ilosc graczy
	void graczPasuje(int _index); //pasuje gracza
	bool graczeWygrana(); //sprawdza czy ktokolwiek zdobyl 21pkt
	int getMaxPkt(); //zwraca pkt najwieksze i mniejsze od 21 pkt zdobyte przez graczy 
	void exportWyniki(); //drukuje wyniki do pliku
	void dodajBota(int _index); //dodaje gracza komputerowego
};