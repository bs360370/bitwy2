

#include "Konny.h"

Konny::Konny(int x, int y, Rozgrywka* rozgrywka): Zwarcie(50,10,70,2,100,0, x, y, rozgrywka) {

}

void Konny::policz_modifier() {

}

char Konny::podaj_typ() {
    return 'k';
}

void Konny::wspieraj() {

}

Wspolrzedne Konny::szukaj_celu() {
    return *polozenie;
}

int Konny::atakuj() {
    return 0;
}



