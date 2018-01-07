

#include "Halabardzista.h"

Halabardzista::Halabardzista(int x, int y, Rozgrywka* rozgrywka): Zwarcie(40,20,40,2,150,0, x, y, rozgrywka) {

}

void Halabardzista::policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) {

    int a = polozenie->get_x();
    int b = polozenie->get_y();
    int wsp1 = tab2[a][b]->get_x();
    int wsp2 = tab2[a][b]->get_y();
    if(tab1[wsp1][wsp2]->podaj_typ() == (char) "K"){
        modifier_atak = 1.5;
    }

    Zwarcie::policz_modifier();

}

char Halabardzista::podaj_typ() {
    return 'H';

}

void Halabardzista::wspieraj() {

}


int Halabardzista::atakuj() {
    return 0;
}
