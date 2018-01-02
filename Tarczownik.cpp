//
// Created by Basia on 28.12.2017.
//

#include "Tarczownik.h"

Tarczownik::Tarczownik(int x, int y, Rozgrywka* rozgrywka): Wsparcie(0,20,100,2,100,0, x, y, rozgrywka) {

}

void Tarczownik::wspieraj() {

}

void Tarczownik::policz_modifier() {

}

char Tarczownik::podaj_typ() {
    return 't';
}

Wspolrzedne Tarczownik::szukaj_celu() {
    return *polozenie;
}

int Tarczownik::atakuj() {
    return 0;
}



