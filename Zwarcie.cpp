

#include <iostream>
#include "Zwarcie.h"
#include "Rozgrywka.h"

Zwarcie::Zwarcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y,
                 Rozgrywka *rozgrywka) : Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale, x, y,
                                                 rozgrywka) {

}

void Zwarcie::policz_modifier() {

    //printf("pol_mod() zwarcia\n");
    if(polozenie->get_x() == 1 || polozenie->get_x() == 4){
        modifier_atak = 0;
    }

}

void Zwarcie::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

void Zwarcie::wspieraj(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

Wspolrzedne *Zwarcie::szukaj_celu(Oddzial ***p, int ro) {

    int linia = polozenie->get_x();
    int rzad = polozenie->get_y();
    //printf(" x = %d, y = %d \n", linia, rzad);
    int at = -1; // linia atakowana
    switch(linia){
        case(2): {
            at = 3;
            break;
        }
        case(3): {
            at = 2;
            break;
        }
        default: {
            //printf("Nie znaleziono celu dla oddzialu z pozycji %d, %d\n", polozenie->get_x(), polozenie->get_y());
            return nullptr; // nie moze atakowac, bo niejest w pierwszym rzedzie swojej armii
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

    //printf("Nie znaleziono celu dla oddzialu z pozycji %d, %d\n", polozenie->get_x(), polozenie->get_y());
    return nullptr;
}