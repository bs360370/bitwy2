//
// Created by Basia on 28.12.2017.
//

#include "Lucznik.h"

Lucznik::Lucznik(): Zasieg(30,5,20,5,200,0) {

}

void Lucznik::policz_modifier() {

}

char Lucznik::podaj_typ() {
    return 'l';
}

void Lucznik::wspieraj() {

}

Wspolrzedne Lucznik::szukaj_celu() {
    return *polozenie;
}

int Lucznik::atakuj() {
    return 0;
}



