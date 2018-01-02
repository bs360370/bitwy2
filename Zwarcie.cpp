//
// Created by Basia on 28.12.2017.
//

#include "Zwarcie.h"

Zwarcie::Zwarcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale):
        Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale) {}

void Zwarcie::policz_modifier() {

}

Wspolrzedne Zwarcie::szukaj_celu() {
    return *polozenie;
}

void Zwarcie::wspieraj() {

}

int Zwarcie::atakuj() {
    return 0;
}
