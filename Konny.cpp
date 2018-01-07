

#include "Konny.h"

Konny::Konny(int x, int y, Rozgrywka* rozgrywka): Zwarcie(50,10,70,2,100,0, x, y, rozgrywka) {

}

char Konny::podaj_typ() {
    return 'K';
}

void Konny::wspieraj() {

}


int Konny::atakuj() {
    return 0;
}

void Konny::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {

    int a = polozenie->get_x();
    int b = polozenie->get_y();
    int wsp1 = tab2[a][b]->get_x();
    int wsp2 = tab2[a][b]->get_y();
    if(tab1[wsp1][wsp2]->podaj_typ() == (char) "k" || tab1[wsp1][wsp2]->podaj_typ() == (char) "L" ){
        modifier_atak = 1.25;
    }

    Zwarcie::policz_modifier();

}



