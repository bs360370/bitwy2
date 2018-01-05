
#include <cstdio>
#include "Lucznik.h"

Lucznik::Lucznik(int x, int y, Rozgrywka* rozgrywka): Zasieg(30,5,20,5,200,0, x, y, rozgrywka) {

}

void Lucznik::policz_modifier() {

}

char Lucznik::podaj_typ() {
    return 'L';
}

void Lucznik::wspieraj() {

}

Wspolrzedne* Lucznik::szukaj_celu(Oddzial*** p) {

    int rzad = polozenie->get_y();
    int pocz = rzad-zasieg+1;
    int kon = rzad-zasieg-1;

    int linia = polozenie->get_x();
    int at; // linia atakowana
    switch(linia){
        case(0):
        case(1):
        case(2): {
            at = 4;
            break;
        }
        case(3):
        case(4):
        case(5): {
            at = 1;
            break;
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

    if(at==1) at = 2;
    if(at==4) at = 3;

    for(int j = pocz; j < kon; ++j){
        if(p[at][j] != nullptr){
            return p[at][j]->polozenie;
        }
    }

    return nullptr;
}

int Lucznik::atakuj() {
    return 0;
}



