

#include "Kusznik.h"
#include <cstdio>

Kusznik::Kusznik(int x, int y, Rozgrywka* rozgrywka): Zasieg(50,8,30,3,150,0, x, y, rozgrywka) {

}

void Kusznik::policz_modifier() {
    printf("pol_mod() kusznika\n");
    if(polozenie->get_x() == 2 || polozenie->get_x() == 3){
        modifier_obrona = 0.7;
    }

}

char Kusznik::podaj_typ() {
    return 'k';
}



int Kusznik::atakuj() {
    return 0;
}

void Kusznik::wspieraj(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

void Kusznik::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {

}



