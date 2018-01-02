//
// Created by Basia on 28.12.2017.
//

#include "Zasieg.h"

Zasieg::Zasieg(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale):
        Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale) {}

void Zasieg::policz_modifier() {

}

Wspolrzedne Zasieg::szukaj_celu() {
    return *polozenie;
}

void Zasieg::wspieraj() {

}

int Zasieg::atakuj() {
    return 0;
}
