//
// Created by Basia on 28.12.2017.
//

#include "Wsparcie.h"

Wsparcie::Wsparcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale):
        Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale) {}

void Wsparcie::policz_modifier() {

}

Wspolrzedne Wsparcie::szukaj_celu() {
    return *polozenie;
}

void Wsparcie::wspieraj() {

}

int Wsparcie::atakuj() {
    return 0;
}
