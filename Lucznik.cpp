
#include <cstdio>
#include "Lucznik.h"

Lucznik::Lucznik(int x, int y, Rozgrywka* rozgrywka): Zasieg(30,5,20,5,200,0, x, y, rozgrywka) {

}

void Lucznik::policz_modifier() {

    if(polozenie->get_x() == 2 || polozenie->get_x() == 3){
        modifier_obrona = 0.5;
        modifier_atak = 0.5;
    }

}

char Lucznik::podaj_typ() {
    return 'L';
}


Wspolrzedne* Lucznik::szukaj_celu(Oddzial*** p, int ro) {

    int rzad = polozenie->get_y();

    int linia = polozenie->get_x();
    int at = -1; // linia atakowana
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

    for(int j = 0; j < zasieg; ++j){
        if(rzad-j >= 0 && rzad+j < ro){
            if(j==0){
                if(p[at][rzad] != nullptr){
                    return p[at][rzad]->get_polozenie();
                }
            }
            else {
                if(p[at][rzad-j] != nullptr){
                    return p[at][rzad-j]->get_polozenie();
                }
                if(p[at][rzad+j] != nullptr){
                    return p[at][rzad+j]->get_polozenie();
                }
            }
        }
    }

    if(at==1) at = 2;
    if(at==4) at = 3;

    for(int j = 0; j < zasieg; ++j){
        if(rzad-j >= 0 && rzad+j < ro){
            if(j==0){
                if(p[at][rzad] != nullptr){
                    return p[at][rzad]->get_polozenie();
                }
            }
            else {
                if(p[at][rzad-j] != nullptr){
                    return p[at][rzad-j]->get_polozenie();
                }
                if(p[at][rzad+j] != nullptr){
                    return p[at][rzad+j]->get_polozenie();
                }
            }
        }
    }

    printf("Nie znaleziono celu dla lucznika z pozycji %d, %d\n", polozenie->get_x(), polozenie->get_y());
    return nullptr;
}

int Lucznik::atakuj() {
    return 0;
}

void Lucznik::wspieraj(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

void Lucznik::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {

}



