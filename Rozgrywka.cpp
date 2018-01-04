

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

void Rozgrywka::poprzesuwaj_1() {

    // I faza: przesuwanie do przodu jesli cos umarlo


    for (int j = 0; j < rozmiar; ++j){
        for(int i = 2; i > 0; --i){
            if (pole[i][j] == nullptr){
                Oddzial* temp;
                temp = pole[i][j];
                pole[i][j] =  pole[i-1][j];
                pole[i-1][j] = temp;
                delete temp;
            }
        }
        for(int i = 3; i < 5; ++i){
            if (pole[i][j] == nullptr){
                Oddzial* temp;
                temp = pole[i][j];
                pole[i][j] = pole[i+j][j];
                pole[i+1][j] = temp;
                delete temp;
            }
        }
    }

}

void Rozgrywka::poprzesuwaj_2() {

    // II faza: przesuwanie kolumn do srodka

    int polowa = rozmiar/2;
    int licznik = 0;
    int tab[10000];

    for(int j = 0; j < rozmiar + 1; ++j){
        tab[j] = 0;
    }

    for(int j = polowa; j >= 0; --j){
        if(pole[2][j] == nullptr && pole[3][j] == nullptr){
            licznik++;
            tab[j] = licznik;
        }
    }

    licznik = 0;

    for(int j = polowa + 1; j < rozmiar; ++j){
        if(pole[2][j] == nullptr && pole[3][j] == nullptr){
            licznik--;
            tab[j] = licznik;
        }
    }


    for(int j = polowa; j >= 0; --j){
        if(tab[j] != 0){
            if(pole[2][j] != nullptr || pole[3][j] != nullptr){
                for(int i = 0; i < 6; ++i){
                    pole[i][j + tab[j]] = pole[i][j];
                    pole[i][j] = nullptr;
                }
            }
        }
    }

    for(int j = polowa + 1; j < rozmiar; ++j){
        if(tab[j] != 0){
            if(pole[2][j] != nullptr || pole[3][j] != nullptr){
                for(int i = 0; i < 6; ++i){
                    pole[i][j + tab[j]] = pole[i][j];
                    pole[i][j] = nullptr;
                }
            }
        }
    }

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
                case 'B':
                    pole[i][j] = new Bebniarz(i, j, this);
                    break;
                case 'H':
                    pole[i][j] = new Halabardzista(i, j, this);
                    break;
                case 'K':
                    pole[i][j] = new Konny(i, j, this);
                    break;
                case 'k':
                    pole[i][j] = new Kusznik(i, j, this);
                    break;
                case 'L':
                    pole[i][j] = new Lucznik(i, j, this);
                    break;
                case 'M':
                    pole[i][j] = new Miecznik(i, j, this);
                    break;
                case 'T':
                    pole[i][j] = new Tarczownik(i, j, this);
                    break;
                default:
                    printf("NIEPOPRAWNE WEJSCIE  pole[%d][%d]= %c !\n", j, i, tab[j][i]);
                    printf("RODZAJ JEDNOSTKI NIEZNANY \nROZGRYWKE USUNIETO \n");
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



