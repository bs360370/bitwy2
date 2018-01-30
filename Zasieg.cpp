

#include <cstdio>
#include <iostream>
#include "Zasieg.h"

using namespace std;

Zasieg::Zasieg(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y,
               Rozgrywka *rozgrywka) : Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale, x, y,
                                               rozgrywka) {
}

void Zasieg::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

void Zasieg::wspieraj(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

bool Zasieg::czy_zasieg() {
    return true;
}

Wspolrzedne *Zasieg::szukaj_celu(Oddzial ***p, int ro) {

    int linia = polozenie->get_x();
    int rzad = polozenie->get_y();

    int at = -1;    // linia atakowana

    switch(linia){
        case(1):
        case(2): {
            at = 3;
            break;
        }
        case(3):
        case(4): {
            at = 2;
            break;
        }
        default: {
            // cout << "Nie znaleziono celu dla oddzialu z pozycji (" << polozenie->get_x() << ", " << polozenie->get_y() << ")" << endl;
            return nullptr;     // nie moze atakowac z linii posilkow
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
    // cout << "Nie znaleziono celu dla oddzialu z pozycji (" << polozenie->get_x() << ", " << polozenie->get_y() << ")" << endl;
    return nullptr;
}