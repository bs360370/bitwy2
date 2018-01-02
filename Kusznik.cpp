//
// Created by Basia on 28.12.2017.
//

#include "Kusznik.h"

Kusznik::Kusznik(): Zasieg(50,8,30,3,150,0) {

}

void Kusznik::policz_modifier() {

}

char Kusznik::podaj_typ() {
    return 'q';
}

void Kusznik::wspieraj() {

}

Wspolrzedne Kusznik::szukaj_celu() {
    return *polozenie;
}

int Kusznik::atakuj() {
    return 0;
}



