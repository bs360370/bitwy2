

#include "Wsparcie.h"


void Wsparcie::policz_modifier() {

}

Wspolrzedne Wsparcie::szukaj_celu() {
    return *polozenie;
}

void Wsparcie::wspieraj() {

}

int Wsparcie::atakuj() {
    return 0;
}

Wsparcie::Wsparcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale, int x, int y,
                   Rozgrywka *rozgrywka) : Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale, x, y,
                                                   rozgrywka) {

}
