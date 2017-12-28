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
    Wspolrzedne polozenie;

    // położenie oddziału
    double modifier_atak;
    double modifier_morale;
    double modifier_obrona;
    // modifiery żyją tylko jedną turę
    // i albo pochodzą od jednostek wsparcia
    // albo są karami
    // na początku tury mają wyjściową wartość 1.0
    virtual void policz_modifier() = 0;
    // liczy modifier w zależności od pozycji
    // i rodzaju przeciwnika
    int policz_atak();
    // liczy według wzoru

public:

    void resetuj_modifiery();
    //  ustawia modifiery oddziału na 1.0
    virtual char podaj_typ() = 0;
    virtual Wspolrzedne szukaj_celu() = 0;
    // podaje cel Oddziału wyliczony na podstawie
    // jego zasięgu i informacji z Rozgrywki o stanie gry
    virtual void wspieraj() = 0;
    void otrzymaj_wsparcie();
    virtual int atakuj() = 0;
    // przekazuje Rozgrywce informację o tym
    // za ile atakowany jest cel
    void aktualizuj_liczebnosc();
    // na podstawie informacji z Rozgrywki
    // po tym jak wykona się policz_straty() w Rozgrywce
    // dany oddział odejmuje sobie liczebność
    void aktualizuj_wspolrzedne();
    void aktualizuj_morale();
    bool czy_martwy();
    // informuje Rozgrywkę o martwym oddziale

    // konstruktory, destruktory

    Oddzial(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale);

    void wypisz_wartosci();
};


#endif //BITWY2_ODDZIAL_H
