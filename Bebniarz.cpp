

#include "Bebniarz.h"

Bebniarz::Bebniarz(int x, int y, Rozgrywka* rozgrywka): Wsparcie(0,1,50,4,40,0, x, y, rozgrywka) {

}

void Bebniarz::wspieraj() {

}

char Bebniarz::podaj_typ() {
    return 'B';
}

void Bebniarz::policz_modifier() {

}


int Bebniarz::atakuj() {
    return 0;
}



