

#include <cstdio>
#include "Rozgrywka.h"
#include "Tarczownik.h"
#include "Bebniarz.h"
#include "Halabardzista.h"
#include "Konny.h"
#include "Kusznik.h"
#include "Lucznik.h"
#include "Miecznik.h"


void Rozgrywka::resetuj_oddzialy() {

}

void Rozgrywka::policz_cele() {

}

void Rozgrywka::policz_wsparcie() {

}

void Rozgrywka::policz_straty() {

}

void Rozgrywka::poprzesuwaj() {

}

void Rozgrywka::wypisz() {
    for(int i = 0; i < 6; ++i) {
        printf("Rzad %d\n", i);
        for (int j = 0; j < rozmiar; ++j) {
            pole[i][j]->wypisz_wartosci();
            printf("\n\n");
        }

    }
}

void Rozgrywka::wykonaj_ture() {

}

void Rozgrywka::czy_koniec_gry() {

}

Rozgrywka::Rozgrywka(int rozmiar, int limit_tur, char tab[][6]) {

    this->rozmiar = rozmiar;
    this->limit_tur = limit_tur;

    this->pole = new Oddzial** [6];
    for (int i = 0; i < 6; ++i) {
        pole[i] = new Oddzial* [rozmiar];
    }
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            switch (tab[j][i]){
                case 'b':
                    pole[i][j] = new Bebniarz(i, j, this);
                    break;
                case 'h':
                    pole[i][j] = new Halabardzista(i, j, this);
                    break;
                case 'k':
                    pole[i][j] = new Konny(i, j, this);
                    break;
                case 'q':
                    pole[i][j] = new Kusznik(i, j, this);
                    break;
                case 'l':
                    pole[i][j] = new Lucznik(i, j, this);
                    break;
                case 'm':
                    pole[i][j] = new Miecznik(i, j, this);
                    break;
                case 't':
                    pole[i][j] = new Tarczownik(i, j, this);
                    break;
                default:
                    printf("NIEOBSLUGIWANY RODZAJ JEDNOSTEK  pole[%d][%d]= %c !\n", j, i, tab[j][i]);
                    delete (this);
            }
        }
    }

    this->tab_wsp = new Wspolrzedne** [6];
    for (int i = 0; i < 6; ++i) {
        tab_wsp[i] = new Wspolrzedne* [rozmiar];
    }
    for (int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            tab_wsp[i][j] = new Wspolrzedne(0,0);
        }
    }

    this->tab_atak = new double* [6];
    for (int i = 0; i < 6; ++i) {
        tab_atak[i] = new double [rozmiar];
    }
    for (int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            tab_atak[i][j] = 0;
        }
    }
}

Rozgrywka::~Rozgrywka() {

    for(int i = 0; i<6; i++) {
        for (int j = 0; j < rozmiar; j++) {
            delete pole[i][j];
        }
        delete pole[i];
    }
    delete pole;

    for(int i = 0; i<6; i++) {
        for (int j = 0; j < rozmiar; j++) {
            delete tab_wsp[i][j];
        }
        delete tab_wsp[i];
    }
    delete tab_wsp;

    for(int i = 0; i<6; i++) {
        delete tab_atak[i];
    }
    delete tab_atak;
}


