//
// Created by Basia on 28.12.2017.
//

#include "Bebniarz.h"

Bebniarz::Bebniarz(): Wsparcie(0,1,50,4,40,0) {

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



