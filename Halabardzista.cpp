

#include "Halabardzista.h"
#include <cstdio>

Halabardzista::Halabardzista(int x, int y, Rozgrywka* rozgrywka): Zwarcie(40,20,40,2,150,0, x, y, rozgrywka) {

}

void Halabardzista::policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) {
    int a = polozenie->get_x();             // moja wspolrzedna x-owa
    int b = polozenie->get_y();             // moja wspolrzedna y-owa
    if(tab2[a][b] != nullptr){
        int wsp1 = tab2[a][b]->get_x();     // x-owa wspolrzedna celu (tab2 wywoluje sie w Rozgrywce jako tab_wsp)
        int wsp2 = tab2[a][b]->get_y();     // y-owa wspolrzenda celu (-||-)
        if(tab1[wsp1][wsp2]->czy_konny()){
            modifier_atak += 0.5;
        }
    }
    Zwarcie::policz_modifier(tab1, tab2);
}

char Halabardzista::podaj_typ() {
    return 'H';
}

void Halabardzista::wspieraj(Oddzial ***tab1, Wspolrzedne ***tab2) {

}