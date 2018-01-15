

#include "Konny.h"
#include <cstdio>

Konny::Konny(int x, int y, Rozgrywka* rozgrywka): Zwarcie(50,10,70,2,100,0, x, y, rozgrywka) {

}


void Konny::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {
    int a = polozenie->get_x();
    int b = polozenie->get_y();
    if(tab2[a][b] != nullptr){
        int wsp1 = tab2[a][b]->get_x();
        int wsp2 = tab2[a][b]->get_y();
        if(tab1[wsp1][wsp2]->czy_zasieg() ){
            modifier_atak *= 1.25;
        }
    }
    Zwarcie::policz_modifier(tab1, tab2);
}

char Konny::podaj_typ() {
    return 'K';
}

void Konny::wspieraj(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

bool Konny::czy_konny() {
    return true;
}