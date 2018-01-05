
#include <cstdio>
#include "Wsparcie.h"


void Wsparcie::policz_modifier() {

}

Wspolrzedne* Wsparcie::szukaj_celu(Oddzial*** p) {

    int rzad = polozenie->get_y();
    int pocz = rzad-zasieg+1;
    int kon = rzad+zasieg-1;

    int linia = polozenie->get_x();
    int at = -1; // linia atakowana
    switch(linia){
        case(0):
        case(1):
        case(2): {
            at = 2;
            break;
        }
        case(3):
        case(4):
        case(5): {
            at = 3;
            break;
        }
        default: {
            printf("blad przy szukaniu celu! \n");
        }
    }

    for(int j = pocz; j < kon; ++j){
        // TODO: trzeba zmienic kolejnosc
        if(j != rzad || linia != at){
            if(p[at][j] != nullptr){
                return p[at][j]->polozenie;
            }
        }
    }
    return polozenie; // nie mamy kogo wspierac -> wspieramy sami siebie
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
