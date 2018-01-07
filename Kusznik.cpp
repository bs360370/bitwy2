

#include "Kusznik.h"

Kusznik::Kusznik(int x, int y, Rozgrywka* rozgrywka): Zasieg(50,8,30,3,150,0, x, y, rozgrywka) {

}

void Kusznik::policz_modifier() {

    if(polozenie->get_x() == 2 || polozenie->get_x() == 3){
        modifier_obrona = 0.7;
    }

}

char Kusznik::podaj_typ() {
    return 'k';
}

void Kusznik::wspieraj() {

}


int Kusznik::atakuj() {
    return 0;
}



