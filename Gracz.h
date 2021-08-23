#pragma once
#include <iostream>
#include <vector>
#include "Karta.h"

class Gracz {
private:
    std::string imie;
    int pkt;
    bool pas;
    bool bot;
    int odwaga;
    std::vector<Karta> rekav; //karty w rece
public:
    Gracz(std::vector<std::shared_ptr <Karta>> _rekav, std::string _imie="", int _pkt=0, bool pas = false, bool bot = false); //tworzy gracza
    Gracz(); //tworzy gracza
    std::string getImie() { return imie; } //zwraca imie 
    void setRekav(Karta karta); //dodaje karte do reki
    void setImie(std::string _imie); //ustawia imie
    void setPkt(); //ustawia pkt
    int getIloscKart() { return rekav.size(); } //zwraca ilosc kart
    int getPkt(); //zwraca ilosc pkt
    void wyswietlKarty(); //wyswietla karty z reki
    bool getPas(); //czy pas
    bool getBot(); //czy bot
    void setOdwaga(int _odwaga); //ustala odwage
    int getOdwaga() { return odwaga; } //zwraca odwage
    void setPas() { pas = true; } //przypisuje pas
    void setBot() { bot = true; } //przypisuje bot
    std::string drukujKarty(); //zwraca karty z reki jako ciag znakow
};