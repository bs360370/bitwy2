

#include "Oddzial.h"
#include "Wspolrzedne.h"
#include <cstdio>

Oddzial::Oddzial(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale, int x, int y, Rozgrywka* rozgr) {

    this->sila_ataku = sila_ataku;
    this->obrona = obrona;
    this->wytrzymalosc = wytrzymalosc;
    this->zasieg = zasieg;
    this->liczebnosc = liczebnosc;
    this->morale = morale;
    this->polozenie = new Wspolrzedne(x, y);
    this->wskaznik_na_Rozgrywke = rozgr;

}

void Oddzial::wypisz_wartosci() {

    printf("sila ataku: %d\n obrona: %d\n wytrzymalosc: %d\n zasieg: %d\n liczebnosc: %d\n morale: %d\n ",
           this->sila_ataku,
           this->obrona,
           this->wytrzymalosc,
           this->zasieg,
           this->liczebnosc,
           this->morale);

}

double Oddzial::policz_atak() {
    return (1+sila_ataku)*(liczebnosc);
}

void Oddzial::resetuj_modifiery() {
    modifier_atak = 1;
    modifier_morale = 1;
    modifier_obrona = 1;
}

void Oddzial::otrzymaj_wsparcie() {

}

void Oddzial::aktualizuj_liczebnosc() {

}

void Oddzial::aktualizuj_wspolrzedne(int x, int y) {
    this->polozenie->set_x(x);
    this->polozenie->set_y(y);

}

void Oddzial::aktualizuj_morale() {

}

bool Oddzial::czy_martwy() {
    return liczebnosc != 0;
}

Oddzial::~Oddzial() {
    delete (polozenie);

}

Wspolrzedne *Oddzial::szukaj_celu(Oddzial ***p) {

    int rzad = polozenie->get_y();
    int pocz = rzad-zasieg+1;
    int kon = rzad+zasieg-1;

    int linia = polozenie->get_x();
    int at = -1; // linia atakowana
    switch(linia){
        case(0):
        case(1):
        case(2): {
            at = 3;
            break;
        }
        case(3):
        case(4):
        case(5): {
            at = 2;
            break;
        }
        default: {
            printf("blad przy szukaniu celu! \n");
        }
    }

    for(int j = pocz; j < kon; ++j){
        // TODO: trzeba zmienic kolejnosc
        if(p[at][j] != nullptr){
            return p[at][j]->polozenie;
        }
    }

    return nullptr;
}


