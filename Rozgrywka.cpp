

#include <cstdio>
#include <iostream>
#include <iomanip>
#include "Rozgrywka.h"
#include "Tarczownik.h"
#include "Bebniarz.h"
#include "Halabardzista.h"
#include "Konny.h"
#include "Kusznik.h"
#include "Lucznik.h"
#include "Miecznik.h"

using namespace std;

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
                case 'X':
                    pole[i][j] = nullptr;
                    break;
                default:
                    cout << "NIEPOPRAWNE WEJSCIE  pole[" << j << "][" << i << "]= " << tab[j][i] << endl;
                    pole[i][j] = nullptr;
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

    this->tab_strat_licz = new double* [6];
    for (int i = 0; i < 6; ++i) {
        tab_strat_licz[i] = new double [rozmiar];
    }
    for (int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            tab_strat_licz[i][j] = 0;
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
        delete tab_wsp[i];
    }
    delete tab_wsp;

    for(int i = 0; i<6; i++) {
        delete tab_strat_licz[i];
    }
    delete tab_strat_licz;
}

bool Rozgrywka::czy_koniec_gry() {
    bool gorne = false;
    bool dolne = false;
    for(int i = 0; i < rozmiar; ++i) {
        if (!gorne) {
            for (int j = 0; j <= 2; ++j) {
                if (pole[j][i] != nullptr) {
                    gorne = true;
                }
            }
        }
        if (!dolne){
            for (int j = 3; j <= 5; ++j) {
                if (pole[j][i] != nullptr) {
                    dolne = true;
                }
            }
        }
        if (dolne && gorne) {
            break;
        }
    }
    return !(dolne && gorne);
}

void Rozgrywka::gra() {
    for(int i = 0; i < limit_tur; ++i){
        if(!this->czy_koniec_gry()){
            this->wykonaj_ture();
        }
        else {
            cout << "gra skonczona przed limitem tur w turze " << i << "." << endl;
            break;
        }
    }
    this->wypisz_ture();
}

void Rozgrywka::wykonaj_ture() {

    // TODO: uzupelnic ta funkcje i nie wiem czy resetuj oddzialy w dobrym miejscy

    this->wypisz_ture();
    aktualna_tura++;

    this->resetuj_oddzialy();
    // cout << "zrobilem reset" << endl;
    this->policz_cele();
    // cout << "policzylem cele" << endl;
    this->policz_modifiery();
    // cout << "policzylem modifiery" << endl;
    this->policz_wsparcie();
    // cout << "policzylem wsparcie" << endl;
    //this->wypisz_modifiery();
    // cout << "wypisalem modifiery" << endl;
    this->policz_atak();
    // cout << "policzylem atak" << endl;
    this->policz_straty_licz();
    // cout << "policzylem straty" << endl;
    //this->wypisz_tab_wsp();
    this->poprzesuwaj_1();
    // cout << "jest po przesuwaniu 1" << endl;
    this->poprzesuwaj_2();
    // cout << "jest po przesuwaniu 2" << endl;
}

void Rozgrywka::wypisz_ture() {

    // TODO: poprawić alignment

    cout << "============";
    for(int k = 0; k< rozmiar; ++k){
        cout << "======";
    }
    cout << endl;
    cout << "Tura " << aktualna_tura << " z " << limit_tur << endl;
    for(int i = 0; i < 6; ++i){
        cout << "            ";
        for(int j = 0; j < rozmiar; ++j){
            if(pole[i][j] != nullptr){
                pole[i][j]->wypisz_status();
            }
            else cout << "  X ";
            cout << "  ";
        }
        cout << endl;
        if(i == 2){
            cout << "------------";
            for(int k = 0; k< rozmiar; ++k){
                cout << "------";
            }
            cout << endl;
        }

    }
}

void Rozgrywka::resetuj_oddzialy() {
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            if(pole[i][j] != nullptr) {
                pole[i][j]->resetuj_modifiery();
                // TODO: reset tab_wsp i tab_strat_licz
            }
        }
    }
}

void Rozgrywka::policz_cele() {
    for(int j = 0; j < rozmiar; ++j){
        for(int i = 0; i < 6; ++i){
            // cout << "policz cele[" << i << "][" << j << "]" << endl;
            if(pole[i][j] != nullptr){
                tab_wsp[i][j] = pole[i][j]->szukaj_celu(pole, rozmiar);
            }
            else {
                tab_wsp[i][j] = nullptr;
            }
        }
    }
}

void Rozgrywka::policz_modifiery() {
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            if(pole[i][j] != nullptr){
                pole[i][j]->policz_modifier(pole, tab_wsp);
            }
        }
    }
}

void Rozgrywka::policz_wsparcie() {
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            if(pole[i][j] != nullptr){
                pole[i][j]->wspieraj(pole, tab_wsp);
            }
        }
    }
}

void Rozgrywka::policz_atak() {

    int wsp_celu_x = 0;
    int wsp_celu_y = 0;
    double moj_atak = 0;
    double strata_celu = 0;

    for(int i = 0; i < 6; ++i) {
        for (int j = 0; j < rozmiar; ++j) {
            tab_strat_licz[i][j] = 0;
        }
    }

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){

            if(pole[i][j] != nullptr && tab_wsp[i][j] != nullptr){

                wsp_celu_x = tab_wsp[i][j]->get_x();
                wsp_celu_y = tab_wsp[i][j]->get_y();

                moj_atak = pole[i][j]->policz_atak();
                strata_celu = pole[wsp_celu_x][wsp_celu_y]->policz_straty(moj_atak);

                tab_strat_licz[wsp_celu_x][wsp_celu_y] += strata_celu;
                pole[wsp_celu_x][wsp_celu_y]->aktualizuj_morale(strata_celu);

            }
        }
    }
}

void Rozgrywka::policz_straty_licz() {

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            if(pole[i][j] != nullptr){
                pole[i][j]->aktualizuj_liczebnosc(tab_strat_licz[i][j]);
                if(pole[i][j]->czy_martwy()){
                    delete(pole[i][j]);
                    pole[i][j] = nullptr;
                }

                if(pole[i][j] == nullptr && i != 0 && i != 5){
                    // TODO: ten if powyzej dos sprawdzenia 12.01.18
                    switch(i){
                        case(1):{
                            if(j > 0 && pole[1][j-1] != nullptr) pole[1][j-1]->aktualizuj_morale_2();
                            if(j < rozmiar-1 && pole[1][j+1] != nullptr) pole[1][j+1]->aktualizuj_morale_2();
                            if(j > 0 && pole[2][j-1] != nullptr) pole[2][j-1]->aktualizuj_morale_2();
                            if(pole[2][j] != nullptr) pole[2][j]->aktualizuj_morale_2();
                            if(j < rozmiar-1 && pole[2][j+1] != nullptr) pole[2][j+1]->aktualizuj_morale_2();
                            break;
                        }
                        case(2):{
                            if(j > 0 && pole[2][j-1] != nullptr) pole[2][j-1]->aktualizuj_morale_2();
                            if(j < rozmiar-1 && pole[2][j+1] != nullptr) pole[2][j+1]->aktualizuj_morale_2();
                            if(j > 0 && pole[1][j-1] != nullptr) pole[1][j-1]->aktualizuj_morale_2();
                            if(pole[1][j] != nullptr) pole[1][j]->aktualizuj_morale_2();
                            if(j < rozmiar-1 && pole[1][j+1] != nullptr) pole[1][j+1]->aktualizuj_morale_2();
                            break;
                        }
                        case(3):{
                            if(j > 0 && pole[3][j-1] != nullptr) pole[3][j-1]->aktualizuj_morale_2();
                            if(j < rozmiar-1 && pole[3][j+1] != nullptr) pole[3][j+1]->aktualizuj_morale_2();
                            if(j > 0 && pole[4][j-1] != nullptr) pole[4][j-1]->aktualizuj_morale_2();
                            if(pole[4][j] != nullptr) pole[4][j]->aktualizuj_morale_2();
                            if(j < rozmiar-1 && pole[4][j+1] != nullptr) pole[4][j+1]->aktualizuj_morale_2();
                            break;
                        }
                        case(4):{
                            if(j > 0 && pole[4][j-1] != nullptr) pole[4][j-1]->aktualizuj_morale_2();
                            if(j < rozmiar-1 && pole[4][j+1] != nullptr) pole[4][j+1]->aktualizuj_morale_2();
                            if(j > 0 && pole[3][j-1] != nullptr) pole[3][j-1]->aktualizuj_morale_2();
                            if(pole[3][j] != nullptr) pole[3][j]->aktualizuj_morale_2();
                            if(j < rozmiar-1 && pole[3][j+1] != nullptr) pole[3][j+1]->aktualizuj_morale_2();
                            break;
                        }
                        default:{
                            cout << "aktualizacja morale: blad: [i][j] = [" << i << "][" << j << "]" << endl;
                        }
                    }
                }
            }
        }
    }
}

void Rozgrywka::poprzesuwaj_1() {

    // I faza: przesuwanie do przodu jesli cos umarlo


    for (int j = 0; j < rozmiar; ++j){
        if (pole[0][j] != nullptr && pole[0][j]->podaj_typ() == 'T' && (pole[1][j] == nullptr || pole[2][j] == nullptr)) {
            // w posilkach jest tarczownik i istnieje jakies wolne pole przed nim
            if (pole[2][j] != nullptr) {
                // jesli na [2][j] nie jest nullptr, to na [1][j] musial byc
                pole[1][j] = pole[2][j];
                pole[1][j]->aktualizuj_wspolrzedne(1, j);
            }
            pole[2][j] = pole[0][j];
            pole[2][j]->aktualizuj_wspolrzedne(2, j);
            pole[0][j] = nullptr;
        } else {
            for (int i = 1; i < 3; ++i) {
                if (pole[i][j] == nullptr) {
                    pole[i][j] = pole[i - 1][j];
                    // TODO: wrzucic te wszystkie ify  z poprzesuwaj1 i poprzesuwaj2 do aktualizuj_wspolrzedne
                    if (pole[i][j] != nullptr) {
                        pole[i][j]->aktualizuj_wspolrzedne(i, j);
                    }
                    pole[i - 1][j] = nullptr;
                }
            }
            if (pole[1][j] == nullptr && pole[0][j] != nullptr) {
                pole[1][j] = pole[0][j];
                if (pole[1][j] != nullptr) {
                    pole[1][j]->aktualizuj_wspolrzedne(1, j);
                }
                pole[0][j] = nullptr;
            }
        }

        if(pole[5][j] != nullptr && pole[5][j]->podaj_typ() == 'T' && (pole[4][j] == nullptr || pole[3][j] == nullptr)) {
            // w posilkach jest tarczownik i istnieje jakies wolne pole przed nim
            if (pole[3][j] != nullptr) {
                // jesli na [3][j] nie jest nullptr, to na [4][j] musial byc
                pole[4][j] = pole[3][j];
                pole[4][j]->aktualizuj_wspolrzedne(4, j);
            }
            pole[3][j] = pole[5][j];
            pole[3][j]->aktualizuj_wspolrzedne(3, j);
            pole[5][j] = nullptr;
        } else {
            for (int i = 4; i > 2; --i) {
                if (pole[i][j] == nullptr) {
                    pole[i][j] = pole[i + 1][j];
                    if (pole[i][j] != nullptr) {
                        pole[i][j]->aktualizuj_wspolrzedne(i, j);
                    }
                    pole[i + 1][j] = nullptr;
                }
            }
            if (pole[4][j] == nullptr && pole[5][j] != nullptr) {
                pole[4][j] = pole[5][j];
                if (pole[4][j] != nullptr) {
                    pole[4][j]->aktualizuj_wspolrzedne(4, j);
                }
                pole[5][j] = nullptr;
            }
        }
    }
}

void Rozgrywka::poprzesuwaj_2() {

    // II faza: przesuwanie kolumn do srodka

    int polowa = (rozmiar/2)-1;
    int licznik = 0;
    int tab[10000];

    for(int armia = 2; armia <= 3; ++armia) {
        for (int j = 0; j < rozmiar + 1; ++j) {
            tab[j] = 0;
        }
        licznik = 0;
        for (int j = polowa; j >= 0; --j) {
            if (pole[armia][j] == nullptr) {
                licznik++;
            }
            tab[j] = licznik;
        }

        licznik = 0;

        for (int j = polowa + 1; j < rozmiar; ++j) {
            if (pole[armia][j] == nullptr) {
                licznik--;
            }
            tab[j] = licznik;
        }

        for (int j = polowa; j >= 0; --j) {
            if (tab[j] != 0) {
                // cout <<"*POLE[2][" << j << "] = nullptr (1 lub 0): " << (pole[2][j]==nullptr) << endl;
                if (pole[armia][j] != nullptr) {
                    int start, koniec;
                    if (armia == 2) {
                        start = 0;
                        koniec = 2;
                    } else {
                        start = 3;
                        koniec = 5;
                    }
                    for (int i = start; i <= koniec; ++i) {
                        pole[i][j + tab[j]] = pole[i][j];
                        if (pole[i][j + tab[j]] != nullptr) {
                            pole[i][j + tab[j]]->aktualizuj_wspolrzedne(i, j + tab[j]);
                        }
                        pole[i][j] = nullptr;
                    }
                }
            }
        }

        for (int j = polowa + 1; j < rozmiar; ++j) {
            if (tab[j] != 0) {
                if (pole[armia][j] != nullptr) {
                    int start, koniec;
                    if (armia == 2) {
                        start = 0;
                        koniec = 2;
                    } else {
                        start = 3;
                        koniec = 5;
                    }
                    for (int i = start; i <= koniec; ++i) {
                        pole[i][j + tab[j]] = pole[i][j];
                        if (pole[i][j + tab[j]] != nullptr) {
                            pole[i][j + tab[j]]->aktualizuj_wspolrzedne(i, j + tab[j]);
                        }
                        pole[i][j] = nullptr;
                    }
                }
            }
        }
    }
}

void Rozgrywka::wypisz() {
    for(int i = 0; i < 6; ++i) {
       cout << "Rzad  " << i << ": ";
        for (int j = 0; j < rozmiar; ++j) {
            pole[i][j]->wypisz_wartosci();
            cout << endl;
        }
    }
}

void Rozgrywka::wypisz_tab_wsp() {
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            cout << "(" << i << ", " << j << "):(";
            cout << setprecision(2) << tab_strat_licz[i][j];
            // TODO: roboczo wypisuje tab_strat_licz
        }
        cout << endl;
    }
}

void Rozgrywka::wypisz_modifiery() {
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            if(pole[i][j] != nullptr) {
                pole[i][j]->wypisz_modifiery();
            }
        }
    }
}
