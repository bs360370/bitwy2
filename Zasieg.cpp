//
// Created by Basia on 28.12.2017.
//

#include "Zasieg.h"

void Zasieg::policz_modifier() {

}

Zasieg::Zasieg(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale):
        Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale) {}

Wspolrzedne Zasieg::szukaj_celu() {
    return Wspolrzedne();
}

void Zasieg::wspieraj() {

}

int Zasieg::atakuj() {
    return 0;
}
