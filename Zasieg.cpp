

#include "Zasieg.h"



void Zasieg::policz_modifier() {

}


void Zasieg::wspieraj() {

}

int Zasieg::atakuj() {
    return 0;
}

Zasieg::Zasieg(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y,
               Rozgrywka *rozgrywka) : Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale, x, y,
                                               rozgrywka) {

}


