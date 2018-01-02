//
// Created by Basia on 28.12.2017.
//

#include "Bebniarz.h"

Bebniarz::Bebniarz(int x, int y, Rozgrywka* rozgrywka): Wsparcie(0,1,50,4,40,0, x, y, rozgrywka) {

}

void Bebniarz::wspieraj() {

}

char Bebniarz::podaj_typ() {
    return 'b';
}

void Bebniarz::policz_modifier() {

}

Wspolrzedne Bebniarz::szukaj_celu() {
    return *polozenie;
}

int Bebniarz::atakuj() {
    return 0;
}



