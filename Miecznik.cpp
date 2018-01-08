

#include "Miecznik.h"



void Miecznik::policz_modifier() {

}

char Miecznik::podaj_typ() {
    return 'M';
}



int Miecznik::atakuj() {
    return 0;
}

Miecznik::Miecznik(int x, int y, Rozgrywka* rozgrywka): Zwarcie(30,20,50,1,200,0, x, y, rozgrywka) {

}

void Miecznik::wspieraj(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

void Miecznik::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {

}



