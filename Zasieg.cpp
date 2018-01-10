

#include "Zasieg.h"

Zasieg::Zasieg(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y,
               Rozgrywka *rozgrywka) : Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale, x, y,
                                               rozgrywka) {
}

void Zasieg::policz_modifier() {

}

void Zasieg::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

void Zasieg::wspieraj(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

bool Zasieg::czy_zasieg() {
    return true;
}

Wspolrzedne *Zasieg::szukaj_celu(Oddzial ***p, int ro) {
    return Oddzial::szukaj_celu(p, ro);
}
