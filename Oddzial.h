//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_ODDZIAL_H
#define BITWY2_ODDZIAL_H


#include "Wspolrzedne.h"
#include "Rozgrywka.h"
#include <string.h>

class Oddzial {
protected:
    const int sila_ataku;
    const int obrona;
    const int wytrzymalosc;
    const int zasieg;
    int liczebmosc;
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
    virtual void policz_modifier();
    // liczy modifier w zależności od pozycji
    // i rodzaju przeciwnika
    int policz_atak();
    // liczy według wzoru

public:

    void resetuj_modifiery();
    //  ustawia modifiery oddziału na 1.0
    virtual char podaj_typ();
    virtual Wspolrzedne szukaj_celu();
    // podaje cel Oddziału wyliczony na podstawie
    // jego zasięgu i informacji z Rozgrywki o stanie gry
    virtual void wspieraj();
    void otrzymaj_wsparcie();
    virtual int atakuj();
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
};


#endif //BITWY2_ODDZIAL_H
