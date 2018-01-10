

#include "Tarczownik.h"

Tarczownik::Tarczownik(int x, int y, Rozgrywka* rozgrywka): Wsparcie(0,20,100,2,100,0, x, y, rozgrywka) {

}

void Tarczownik::wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) {
    int a = polozenie->get_x();         // moja wspolrzedna x-owa
    int b = polozenie->get_y();         // moja wspolrzedna y-owa
    int wsp1 = tab2[a][b]->get_x();     // x-owa wspolrzedna celu (tab2 wywoluje sie w Rozgrywce jako tab_wsp)
    int wsp2 = tab2[a][b]->get_y();     // y-owa wspolrzenda celu (-||-)
    // tab1[wsp1][wsp2] to wskaznik na cel, bo tab1 wywoluje sie w Rozgrywce jako pole
    tab1[wsp1][wsp2]->modifier_obrona = 1.5;
}

void Tarczownik::policz_modifier() {

}

char Tarczownik::podaj_typ() {
    return 'T';
}

void Tarczownik::policz_modifier(Oddzial ***tab1, Wspolrzedne ***tab2) {

}