
#include <iostream>
#include "Zwarcie.h"
#include "Rozgrywka.h"

void Zwarcie::policz_modifier() {

}

Wspolrzedne* Zwarcie::szukaj_celu(Oddzial*** p) {

    int rzad = polozenie->get_y();
    int pocz = rzad-zasieg+1;
    int kon = rzad-zasieg-1;

    int linia = polozenie->get_x();
    int at; // linia atakowana
    switch(linia){
        case(0,1,2): {
            at = 3;
        }
        case(3,4,5): {
            at = 2;
        }
        default: {
            printf("blad przy szukaniu celu! \n");
        }
    }

    for(int j = pocz; j < kon; ++j){
        if(p[at][j] != nullptr){
            return p[at][j]->polozenie;
        }
    }
    return nullptr;
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
