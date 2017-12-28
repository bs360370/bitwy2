//
// Created by Basia on 28.12.2017.
//

#include "Wsparcie.h"

void Wsparcie::policz_modifier() {

}

Wsparcie::Wsparcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale) : Oddzial(
        sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale) {

}

Wspolrzedne Wsparcie::szukaj_celu() {
    return Wspolrzedne();
}

void Wsparcie::wspieraj() {

}

int Wsparcie::atakuj() {
    return 0;
}
