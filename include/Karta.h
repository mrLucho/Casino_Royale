//
// Created by micha on 13.04.2022.
//

#ifndef CASINO_ROYALE_KARTA_H
#define CASINO_ROYALE_KARTA_H
#pragma once
#include <iostream>



class Karta {
private:
    char kolor;
    char figura;
    int wartosc;
public:
    Karta(int _kolor = 0, int _wartosc = 0);
    void setKolor(int _kolor);
    void setWartosc(int _wartosc);
    char getKolor() const { return kolor; }
    char getFigura() const { return figura; }
    int getWartosc() const { return wartosc; }
    void wypisz() const { std::cout << figura << kolor; }
};
std::ostream &operator<<(std::ostream &os, const Karta& card);


#endif //CASINO_ROYALE_KARTA_H
