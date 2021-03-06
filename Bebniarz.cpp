

#include "Bebniarz.h"

Bebniarz::Bebniarz(int x, int y, Rozgrywka* rozgrywka): Wsparcie(0,1,50,4,40,0, x, y, rozgrywka) {

}

void Bebniarz::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {

}

char Bebniarz::podaj_typ() {
    return 'B';
}

void Bebniarz::wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) {
    int a = polozenie->get_x();                                     // moja wspolrzedna x-owa
    int b = polozenie->get_y();                                     // moja wspolrzedna y-owa
    if(tab2[a][b] != nullptr) {
        int wsp1 = tab2[a][b]->get_x();                             // x-owa wspolrzedna celu (tab2 wywoluje sie w Rozgrywce jako tab_wsp)
        int wsp2 = tab2[a][b]->get_y();                             // y-owa wspolrzenda celu (-||-)
        tab1[wsp1][wsp2]->otrzymaj_wsparcie(0.0, 0.0, 0.5, -0.5);   // tab1[wsp1][wsp2] to wskaznik na cel, bo tab1 wywoluje sie w Rozgrywce jako pole
    }
}