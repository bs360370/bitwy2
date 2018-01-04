

#include "Zasieg.h"



void Zasieg::policz_modifier() {

}

Wspolrzedne Zasieg::szukaj_celu() {
    return *polozenie;
}

void Zasieg::wspieraj() {

}

int Zasieg::atakuj() {
    return 0;
}

Zasieg::Zasieg(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale, int x, int y,
               Rozgrywka *rozgrywka) : Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale, x, y,
                                               rozgrywka) {

}
