//
// Created by Basia on 28.12.2017.
//

#include "Oddzial.h"
#include <cstdio>


int Oddzial::policz_atak() {
    return 0;
}

void Oddzial::resetuj_modifiery() {

}

void Oddzial::otrzymaj_wsparcie() {

}

void Oddzial::aktualizuj_liczebnosc() {

}

void Oddzial::aktualizuj_wspolrzedne() {

}

void Oddzial::aktualizuj_morale() {

}

bool Oddzial::czy_martwy() {
    return false;
}

Oddzial::Oddzial(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale) {

    this->sila_ataku = sila_ataku;
    this->obrona = obrona;
    this->wytrzymalosc = wytrzymalosc;
    this->zasieg = zasieg;
    this->liczebnosc = liczebnosc;
    this->morale = morale;

}

void Oddzial::wypisz_wartosci() {

    printf("sila ataku: %d\n obrona: %d\n wytrzymalosc: %d\n zasieg: %d\n liczebnosc: %d\n morale: %d\n ",
           this->sila_ataku,
           this->obrona,
           this->wytrzymalosc,
           this->zasieg,
           this->liczebnosc,
           this->morale);

}
