
#include <iostream>
#include "Zwarcie.h"
#include "Rozgrywka.h"

void Zwarcie::policz_modifier() {

    if(polozenie->get_x() == 1 || polozenie->get_x() == 4){
        modifier_atak = 0;
    }

}


void Zwarcie::wspieraj() {

}

int Zwarcie::atakuj() {
    return 0;
}

Zwarcie::Zwarcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale, int x, int y,
                 Rozgrywka *rozgrywka) : Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale, x, y,
                                                 rozgrywka) {

}


