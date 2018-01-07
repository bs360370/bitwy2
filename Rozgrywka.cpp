

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

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            if(pole[i][j] != nullptr) {
                pole[i][j]->resetuj_modifiery();
                // TODO: zaimplementuj resetowanie modifierow w Oddziale
            }
        }
    }
}

void Rozgrywka::policz_cele() {

    for(int j = 0; j < rozmiar; ++j){
        for(int i = 0; i < 6; ++i){
            tab_wsp[i][j] = pole[i][j]->szukaj_celu(pole, rozmiar);
        }
    }
}

void Rozgrywka::policz_wsparcie() {

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){

            pole[i][j]->wspieraj(pole, tab_wsp);

        }
    }

}


void Rozgrywka::poprzesuwaj_1() {

    // I faza: przesuwanie do przodu jesli cos umarlo


    for (int j = 0; j < rozmiar; ++j){
        for(int i = 1; i < 3; ++i){
            if (pole[i][j] == nullptr){
                pole[i][j] =  pole[i-1][j];
                pole[i-1][j] = nullptr;
            }
        }
        if (pole[1][j] == nullptr && pole[0][j] != nullptr) {
            pole[1][j] = pole[0][j];
            pole[0][j] = nullptr;
        }
        for(int i = 4; i > 2; --i){
            if (pole[i][j] == nullptr){
                pole[i][j] = pole[i+j][j];
                pole[i+1][j] = nullptr;
            }
        }
        if (pole[4][j] == nullptr && pole[5][j] != nullptr) {
            pole[4][j] = pole[5][j];
            pole[5][j] = nullptr;
        }
    }

}

void Rozgrywka::poprzesuwaj_2() {

    // II faza: przesuwanie kolumn do srodka

    int polowa = rozmiar/2;
    int licznik = 0;
    int tab[1000000];

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

    // TODO: uzupelnic ta funkcje i nie wiem czy reseyuj oddzialy w dobrym miejscy

    this->wypisz_ture();
    aktualna_tura++;

    this->resetuj_oddzialy();
    this->policz_cele();            // wpisanie wspolrzednych celu do tab_wsp
    this->policz_modifiery();
    this->policz_wsparcie();
    this->policz_atak();
    this->policz_straty_licz();
    this->poprzesuwaj_1();
    this->poprzesuwaj_2();

}

bool Rozgrywka::czy_koniec_gry() {

    int pol = rozmiar/2;
    return pole[2][pol] == nullptr && pole[2][pol + 1] == nullptr && pole[3][pol] == nullptr && pole[3][pol + 1] == nullptr;
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
        for (int j = 0; j < rozmiar; j++) {
            delete tab_wsp[i][j];
        }
        delete tab_wsp[i];
    }
    delete tab_wsp;

    for(int i = 0; i<6; i++) {
        delete tab_strat_licz[i];
    }
    delete tab_strat_licz;
}

void Rozgrywka::gra() {

    for(int i = 0; i < limit_tur; ++i){

        if(!this->czy_koniec_gry()){
            this->wykonaj_ture();
        }
        else {
            printf("gra skonczona przed limitem tur w turze %d.\n", i+1);
            i = limit_tur;
        }
    }
}

void Rozgrywka::wypisz_ture() {

    // TODO: poprawić alignment

    printf("==================================================\n");

    printf("Tura %d z %d \n", aktualna_tura, limit_tur);
    for(int i = 0; i < 6; ++i){
        printf("            ");
        for(int j = 0; j < rozmiar; ++j){
            if(pole[i][j] != nullptr){
                pole[i][j]->wypisz_status();
            }
            else printf(" X ");
            printf ("  ");
        }
        printf("\n");
        if(i == 2) printf("--------------------------------------------------\n");
    }
    printf("==================================================\n");
}

void Rozgrywka::policz_atak() {

    int wsp_celu_x = 0;
    int wsp_celu_y = 0;
    double moj_atak = 0;
    int strata_celu = 0;

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){

            wsp_celu_x = tab_wsp[i][j]->get_x();
            wsp_celu_y = tab_wsp[i][j]->get_y();

            moj_atak = pole[i][j]->policz_atak();
            strata_celu = pole[wsp_celu_x][wsp_celu_y]->policz_straty(moj_atak);

            // pole[wsp_celu_x][wsp_celu_y]->aktualizuj_liczebnosc(strata_celu); <- to nie moze byc bo morele aktualizuja sie wzgledem jednej liczebnosci w calej turze

            tab_strat_licz[wsp_celu_x][wsp_celu_y] = tab_strat_licz[wsp_celu_x][wsp_celu_y] + strata_celu;
            pole[wsp_celu_x][wsp_celu_y]->aktualizuj_morale(strata_celu);

        }
    }
}

void Rozgrywka::policz_modifiery() {
// TODO: trzeba zrobic porzadek bo teraz policz modifier bezargumentowy może wywolywac sie dwa razy, bo w halab i konnym wywoluje sie dwa razy
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){

            pole[i][j]->policz_modifier(pole, tab_wsp);
            pole[i][j]->policz_modifier();

        }
    }
}

void Rozgrywka::policz_straty_licz() {

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            if(pole[i][j] != nullptr){
                pole[i][j]->aktualizuj_liczebnosc(tab_strat_licz[i][j]);
                if(pole[i][j] == nullptr){
                    switch(i){
                        case(1):{
                            if(pole[1][j-1] != nullptr) pole[1][j-1]->aktualizuj_morale_2();
                            if(pole[1][j+1] != nullptr) pole[1][j+1]->aktualizuj_morale_2();
                            if(pole[2][j-1] != nullptr) pole[2][j-1]->aktualizuj_morale_2();
                            if(pole[2][j] != nullptr) pole[2][j]->aktualizuj_morale_2();
                            if(pole[2][j+1] != nullptr) pole[2][j+1]->aktualizuj_morale_2();
                        }
                        case(2):{
                            if(pole[2][j-1] != nullptr) pole[2][j-1]->aktualizuj_morale_2();
                            if(pole[2][j+1] != nullptr) pole[2][j+1]->aktualizuj_morale_2();
                            if(pole[1][j-1] != nullptr) pole[1][j-1]->aktualizuj_morale_2();
                            if(pole[1][j] != nullptr) pole[1][j]->aktualizuj_morale_2();
                            if(pole[1][j+1] != nullptr) pole[1][j+1]->aktualizuj_morale_2();
                        }
                        case(3):{
                            if(pole[3][j-1] != nullptr) pole[3][j-1]->aktualizuj_morale_2();
                            if(pole[3][j+1] != nullptr) pole[3][j+1]->aktualizuj_morale_2();
                            if(pole[4][j-1] != nullptr) pole[4][j-1]->aktualizuj_morale_2();
                            if(pole[4][j] != nullptr) pole[4][j]->aktualizuj_morale_2();
                            if(pole[4][j+1] != nullptr) pole[4][j+1]->aktualizuj_morale_2();
                        }
                        case(4):{
                            if(pole[4][j-1] != nullptr) pole[4][j-1]->aktualizuj_morale_2();
                            if(pole[4][j+1] != nullptr) pole[4][j+1]->aktualizuj_morale_2();
                            if(pole[3][j-1] != nullptr) pole[3][j-1]->aktualizuj_morale_2();
                            if(pole[3][j] != nullptr) pole[3][j]->aktualizuj_morale_2();
                            if(pole[3][j+1] != nullptr) pole[3][j+1]->aktualizuj_morale_2();
                        }
                        default:{
                            printf("BLAD: zostal zaatakowany zly oddzial\n");
                        }
                    }
                }
            }
        }
    }
}









