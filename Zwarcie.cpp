

#include "Zwarcie.h"

void Zwarcie::policz_modifier() {

}

Wspolrzedne Zwarcie::szukaj_celu() {
    return *polozenie;
}

void Zwarcie::wspieraj() {

}

int Zwarcie::atakuj() {
    return 0;
}

Zwarcie::Zwarcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale, int x, int y,
                 Rozgrywka *rozgrywka) : Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale, x, y,
                                                 rozgrywka) {

}
