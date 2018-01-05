

#include "Halabardzista.h"

Halabardzista::Halabardzista(int x, int y, Rozgrywka* rozgrywka): Zwarcie(40,20,40,2,150,0, x, y, rozgrywka) {

}

void Halabardzista::policz_modifier() {

}

char Halabardzista::podaj_typ() {
    return 'H';

}

void Halabardzista::wspieraj() {

}


int Halabardzista::atakuj() {
    return 0;
}
