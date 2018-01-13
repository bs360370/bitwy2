

#include "Halabardzista.h"
#include <cstdio>

Halabardzista::Halabardzista(int x, int y, Rozgrywka* rozgrywka): Zwarcie(40,20,40,2,150,0, x, y, rozgrywka) {

}

void Halabardzista::policz_modifier() {
    //printf("pol_mod() halabardzisty\n");
    //Zwarcie::policz_modifier();
}

void Halabardzista::policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) {
    //printf("pol_mod(* *) halabardzisty\n");
    int a = polozenie->get_x();         // moja wspolrzedna x-owa
    int b = polozenie->get_y();         // moja wspolrzedna y-owa
    if(tab2[a][b] != nullptr){
        int wsp1 = tab2[a][b]->get_x();     // x-owa wspolrzedna celu (tab2 wywoluje sie w Rozgrywce jako tab_wsp)
        int wsp2 = tab2[a][b]->get_y();     // y-owa wspolrzenda celu (-||-)
        if(tab1[wsp1][wsp2]->czy_konny()){
            modifier_atak *= 1.5;
        }
    }
    //TODO: nie wiem czy ten this jest potrzebny
    this->Zwarcie::policz_modifier();
    // printf("tutaj\n");

}

char Halabardzista::podaj_typ() {
    return 'H';
}

void Halabardzista::wspieraj(Oddzial ***tab1, Wspolrzedne ***tab2) {

}