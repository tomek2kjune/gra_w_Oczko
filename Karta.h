#pragma once
#include <iostream>

class Karta {
private:
    char kolor;
    char figura;
    int wartosc;
public:
    Karta(int _kolor = 0, int _wartosc = 0); //tworzy karte
    void setKolor(int _kolor); //ustawia kolor
    void setWartosc(int _wartosc); //ustawia wartosc
    char getKolor() const { return kolor; } //zwraca kolor
    char getFigura() const { return figura; } //zwraca figure
    int getWartosc() const { return wartosc; } //zwraca wartosc
    void wypisz() const { std::cout << figura << kolor; } //wypisuje karte
};