

#include <cstdio>
#include "Lucznik.h"

Lucznik::Lucznik(int x, int y, Rozgrywka* rozgrywka): Zasieg(30,5,20,5,200,0, x, y, rozgrywka) {

}


void Lucznik::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {
    //printf("pol_mod() lucznika\n");
    if(polozenie->get_x() == 2 || polozenie->get_x() == 3){
        modifier_obrona *= 0.5;
        modifier_atak *= 0.5;
    }
}

char Lucznik::podaj_typ() {
    return 'L';
}

void Lucznik::wspieraj(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

Wspolrzedne* Lucznik::szukaj_celu(Oddzial*** p, int ro) {

    int rzad = polozenie->get_y();
    int linia = polozenie->get_x();
    //printf(" x = %d, y = %d \n", linia, rzad);
    int at = -1; // linia atakowana

    switch(linia){
        case(1):
        case(2): {
            at = 4;
            break;
        }
        case(3):
        case(4): {
            at = 1;
            break;
        }
        default: {
            //printf("Nie znaleziono celu dla oddzialu z pozycji %d, %d\n", polozenie->get_x(), polozenie->get_y());
            return nullptr; // lucznik nie moze atakowac z linii rezerw
        }
    }

    for(int j = 0; j < zasieg; ++j){
        if(j==0){
            if(p[at][rzad] != nullptr){
                return p[at][rzad]->get_polozenie();
            }
        }
        else {
            if(rzad-j >= 0 && p[at][rzad-j] != nullptr){
                return p[at][rzad-j]->get_polozenie();
            }
            if(rzad+j < ro && p[at][rzad+j] != nullptr){
                return p[at][rzad+j]->get_polozenie();
            }
        }
    }

    if(at==1) at = 2;
    if(at==4) at = 3;

    for(int j = 0; j < zasieg; ++j){
        if(j==0){
            if(p[at][rzad] != nullptr){
                return p[at][rzad]->get_polozenie();
            }
        }
        else {
            if(rzad-j >= 0 && p[at][rzad-j] != nullptr){
                return p[at][rzad-j]->get_polozenie();
            }
            if(rzad+j < ro && p[at][rzad+j] != nullptr){
                return p[at][rzad+j]->get_polozenie();
            }
        }
    }
    //printf("Nie znaleziono celu dla lucznika z pozycji %d, %d\n", polozenie->get_x(), polozenie->get_y());
    return nullptr;
}