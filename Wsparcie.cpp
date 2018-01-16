

#include <cstdio>
#include <iostream>
#include "Wsparcie.h"

using namespace std;

Wsparcie::Wsparcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y,
                   Rozgrywka *rozgrywka) : Oddzial(sila_ataku, obrona, wytrzymalosc, zasieg, liczebnosc, morale, x, y,
                                                   rozgrywka) {
}


void Wsparcie::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

Wspolrzedne* Wsparcie::szukaj_celu(Oddzial*** p, int ro) {

    int rzad = polozenie->get_y();
    int linia = polozenie->get_x();

    int at = -1;        // linia atakowana

    switch(linia){
        case(0):
        case(1):
        case(2): {
            at = 2;
            break;
        }
        case(3):
        case(4):
        case(5): {
            at = 3;
            break;
        }
        default: {
            cout << "blad przy szukaniu celu!" << endl;
        }
    }

    for(int j = 0; j < zasieg; ++j){
        if(j==0){
            if(linia != at){
                if(p[at][rzad] != nullptr){
                    return p[at][rzad]->get_polozenie();
                    // TODO: TUTAJ COS SIE PSUJE
                }
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
    return polozenie;   // nie mamy kogo wspierac -> wspieramy sami siebie
}

void Wsparcie::wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) {

}