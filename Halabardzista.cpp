//
// Created by Basia on 28.12.2017.
//

#include "Halabardzista.h"

Halabardzista::Halabardzista(): Zwarcie(40,20,40,2,150,0) {

}

void Halabardzista::policz_modifier() {

}

char Halabardzista::podaj_typ() {
    return 'h';

}

void Halabardzista::wspieraj() {

}

Wspolrzedne Halabardzista::szukaj_celu() {
    return *polozenie;
}

int Halabardzista::atakuj() {
    return 0;
}
