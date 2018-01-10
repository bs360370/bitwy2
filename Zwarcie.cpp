

#include <iostream>
#include "Zwarcie.h"
#include "Rozgrywka.h"

Zwarcie::Zwarcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y,
                 Rozgrywka *rozgrywka) : Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale, x, y,
                                                 rozgrywka) {

}

void Zwarcie::policz_modifier() {

    printf("pol_mod() zwarcia\n");
    if(polozenie->get_x() == 1 || polozenie->get_x() == 4){
        modifier_atak = 0;
    }

}

void Zwarcie::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

void Zwarcie::wspieraj(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

Wspolrzedne *Zwarcie::szukaj_celu(Oddzial ***p, int ro) {
    return Oddzial::szukaj_celu(p, ro);
}
