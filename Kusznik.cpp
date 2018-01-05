

#include "Kusznik.h"

Kusznik::Kusznik(int x, int y, Rozgrywka* rozgrywka): Zasieg(50,8,30,3,150,0, x, y, rozgrywka) {

}

void Kusznik::policz_modifier() {

}

char Kusznik::podaj_typ() {
    return 'k';
}

void Kusznik::wspieraj() {

}

Wspolrzedne* Kusznik::szukaj_celu() {
    return polozenie;
}

int Kusznik::atakuj() {
    return 0;
}



