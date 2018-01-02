//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_ODDZIAL_H
#define BITWY2_ODDZIAL_H


#include "Wspolrzedne.h"
#include <string.h>

class Rozgrywka;

class Oddzial {

protected:
    int sila_ataku;
    int obrona;
    int wytrzymalosc;
    int zasieg;
    int liczebnosc;
    int morale;

    Rozgrywka* wskaznik_na_Rozgrywke;
    Wspolrzedne* polozenie;

    double modifier_atak;
    double modifier_morale;
    double modifier_obrona;
    virtual void policz_modifier() = 0;
    int policz_atak();

public:

    void resetuj_modifiery();
    virtual char podaj_typ() = 0;
    virtual Wspolrzedne szukaj_celu() = 0;
    virtual void wspieraj() = 0;
    void otrzymaj_wsparcie();
    virtual int atakuj() = 0;
    void aktualizuj_liczebnosc();
    void aktualizuj_wspolrzedne(int x, int y);
    void aktualizuj_morale();
    bool czy_martwy();

    Oddzial(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale, int x, int y, Rozgrywka* rozgr);
    ~Oddzial();

    void wypisz_wartosci();
};


#endif //BITWY2_ODDZIAL_H
