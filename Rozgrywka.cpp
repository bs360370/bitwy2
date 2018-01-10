

#include <cstdio>
#include "Rozgrywka.h"
#include "Tarczownik.h"
#include "Bebniarz.h"
#include "Halabardzista.h"
#include "Konny.h"
#include "Kusznik.h"
#include "Lucznik.h"
#include "Miecznik.h"

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
                    // TODO: ponizszy case to eksperyment !
                case 'X':
                    pole[i][j] = nullptr;
                    break;
                default:
                    printf("NIEPOPRAWNE WEJSCIE  pole[%d][%d]= %c !\n", j, i, tab[j][i]);
                    printf("RODZAJ JEDNOSTKI NIEZNANY \nROZGRYWKE USUNIETO \n");
                    delete (this); // TODO: zmienic to bo jest zdecydowanie zle !!!!!!!!!
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

bool Rozgrywka::czy_koniec_gry() {
    int pol = rozmiar/2-1;
    return (pole[2][pol] == nullptr && pole[2][pol + 1] == nullptr) || (pole[3][pol] == nullptr && pole[3][pol + 1] == nullptr);
}

void Rozgrywka::gra() {
    for(int i = 0; i < limit_tur; ++i){
        if(!this->czy_koniec_gry()){
            //printf("check przed tura %d\n", i);
            this->wykonaj_ture();
            //printf("check po turze  %d\n", i);
        }
        else {
            printf("gra skonczona przed limitem tur w turze %d.\n", i+1);
            i = limit_tur;
        }
    }
}

void Rozgrywka::wykonaj_ture() {

    // TODO: uzupelnic ta funkcje i nie wiem czy reseyuj oddzialy w dobrym miejscy

    this->wypisz_ture();
    aktualna_tura++;

    this->resetuj_oddzialy();
    printf("zrobilem reset\n");
    this->policz_cele();            // wpisanie wspolrzednych celu do tab_wsp
    printf("policzylem cele\n");
    this->wypisz_tab_wsp();
    this->policz_modifiery();
    printf("policzylem modifiery\n");
    this->policz_wsparcie();
    printf("policzylem wsparcie\n");
    this->policz_atak();
    printf("policzylem atak\n");
    this->policz_straty_licz();
    printf("policzylem straty\n");
    this->poprzesuwaj_1();
    printf("jest po przesuwaniu 1\n");
    this->poprzesuwaj_2();
    printf("jest po przesuwaniu 2\n");
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
            else printf(" XS ");
            printf ("  ");
        }
        printf("\n");
        if(i == 2) printf("--------------------------------------------------\n");
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
            printf("policz cele[%d][%d]\n", i, j);
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
// TODO: TUTAJ SIE WYWALA PROGRAM 8 STYCZNIA 2018
    printf("poczatek modifierow\n");
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            if(pole[i][j] != nullptr){
                pole[i][j]->policz_modifier(pole, tab_wsp);
                pole[i][j]->policz_modifier();
            }
        }
    }
    printf("koniec modifierow\n");
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

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){

            if(pole[i][j] != nullptr && tab_wsp[i][j] != nullptr){

                wsp_celu_x = tab_wsp[i][j]->get_x();
                wsp_celu_y = tab_wsp[i][j]->get_y();

                moj_atak = pole[i][j]->policz_atak();
                printf("policzylem atak w policz_ataku()\n");
                strata_celu = pole[wsp_celu_x][wsp_celu_y]->policz_straty(moj_atak);
                printf("policzylem straty w policz_ataku()\n");

                tab_strat_licz[wsp_celu_x][wsp_celu_y] = tab_strat_licz[wsp_celu_x][wsp_celu_y] + strata_celu;
                pole[wsp_celu_x][wsp_celu_y]->aktualizuj_morale(strata_celu);
            }


        }
    }
}

void Rozgrywka::policz_straty_licz() {

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < rozmiar; ++j){
            if(pole[i][j] != nullptr && tab_wsp[i][j] != nullptr){
                pole[i][j]->aktualizuj_liczebnosc(tab_strat_licz[tab_wsp[i][j]->get_x()][tab_wsp[i][j]->get_y()]);
                if(pole[i][j]->aktualna_liczebnosc == 0){

                    pole[i][j] = nullptr;
                    printf(" *pole[%d][%d] chce byc nullpointerem* \n", i, j);
                    if (pole[i][j] == nullptr){
                        printf(" *pole[%d][%d] jest nullpointerem* \n", i, j);
                    }
                    // TODO: to jest eksperyment i nie wiem czy zadziala
                }
                /*
                if(pole[i][j] == nullptr){

                    // TODO: z funkcja aktualizuj_morale_2 cos jest nietak

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
                */
            }
        }
    }
}

void Rozgrywka::poprzesuwaj_1() {

    // I faza: przesuwanie do przodu jesli cos umarlo

    printf("*jestemw fazie 0 W P1\n");

    for (int j = 0; j < rozmiar; ++j){
        //printf("*J = %d*\n", j);
        for(int i = 1; i < 3; ++i){
            if (pole[i][j] == nullptr){
                pole[i][j] =  pole[i-1][j];
                // TODO: wrzucic te wszystkie ify  z poprzesuwaj1 i poprzesuwaj2 do aktualizuj_wspolrzedne
                if(pole[i][j] != nullptr){
                    printf("pole[%d][%d] nie jest pustym wsk\n", i, j);
                    pole[i][j]->aktualizuj_wspolrzedne(i,j);
                }
                pole[i-1][j] = nullptr;
            }
        }
        if (pole[1][j] == nullptr && pole[0][j] != nullptr) {
            //printf("*if check*\n");
            pole[1][j] = pole[0][j];
            if(pole[1][j] != nullptr){
                printf("pole[1][%d] nie jest pustym wsk",  j);
                pole[1][j]->aktualizuj_wspolrzedne(1,j);
            }
            pole[0][j] = nullptr;
        }
        for(int i = 4; i > 2; --i){
            if (pole[i][j] == nullptr){
                //printf("*if check FOR2*\n");
                pole[i][j] = pole[i+1][j];
                if(pole[i][j] != nullptr){
                    printf("pole[%d][%d] nie jest pustym wsk", i, j);
                    pole[i][j]->aktualizuj_wspolrzedne(i,j);
                }
                pole[i+1][j] = nullptr;
            }
        }
        if (pole[4][j] == nullptr && pole[5][j] != nullptr) {
            //printf("*if check*\n");
            pole[4][j] = pole[5][j];
            if(pole[4][j] != nullptr){
                printf("pole[4][%d] nie jest pustym wsk",  j);
                pole[4][j]->aktualizuj_wspolrzedne(4,j);
            }
            pole[5][j] = nullptr;
        }

    }
    //printf("*jestemw fazie KNC W P1\n");
}

void Rozgrywka::poprzesuwaj_2() {

    // II faza: przesuwanie kolumn do srodka

    printf("*jestemw fazie 0 Z P2\n");

    int polowa = (rozmiar/2)-1;
    int licznik = 0;
    int tab[10000];

    //printf("*jestem w fazie 1*\n");

    for(int j = 0; j < rozmiar + 1; ++j){
        tab[j] = 0;
    }

    for(int j = polowa; j >= 0; --j){
        if(pole[2][j] == nullptr && pole[3][j] == nullptr){
            licznik++;
        }
        tab[j] = licznik;
    }

    licznik = 0;

    for(int j = polowa + 1; j < rozmiar; ++j){
        if(pole[2][j] == nullptr && pole[3][j] == nullptr){
            licznik--;
        }
        tab[j] = licznik;
    }

    for(int j = 0; j < rozmiar; ++j){
            //printf("tab_licznikow_porz_2[%d] = %d\n", j, tab[j]);
    }

    for(int j = polowa; j >= 0; --j){
        if(tab[j] != 0){
            //printf("*POLE[2][%d] = nullptr (1 lub 0): %d*\n", j, (pole[2][j]==nullptr));
            if(pole[2][j] != nullptr || pole[3][j] != nullptr){
                //printf("*JESTEM W IFIE*\n");
                for(int i = 0; i < 6; ++i){
                    pole[i][j + tab[j]] = pole[i][j];
                    if(pole[i][j + tab[j]] != nullptr){
                        printf("pole[%d][%d] nie jest pustym wsk", i, j);
                        pole[i][j + tab[j]]->aktualizuj_wspolrzedne(i,j + tab[j]);
                    }
                    pole[i][j] = nullptr;
                    //printf("*pole na nullptr 1!");
                }
            }
        }
    }

    for(int j = polowa + 1; j < rozmiar; ++j){
        if(tab[j] != 0){
            if(pole[2][j] != nullptr || pole[3][j] != nullptr){
                for(int i = 0; i < 6; ++i){
                    pole[i][j + tab[j]] = pole[i][j];
                    if(pole[i][j + tab[j]] != nullptr){
                        printf("pole[%d][%d] nie jest pustym wsk", i, j);
                        pole[i][j + tab[j]]->aktualizuj_wspolrzedne(i,j + tab[j]);
                    }
                    pole[i][j] = nullptr;
                    //printf("*pole na nullptr 2!");
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

void Rozgrywka::wypisz_tab_wsp() {
    printf("jestem w wypisz_tab_wsp 1\n");
    for(int i = 0; i < 6; ++i){
        printf("jestem w wypisz_tab_wsp 2\n");
        for(int j = 0; j < rozmiar; ++j){
            printf("jestem w wypisz_tab_wsp 3\n");
            if(tab_wsp[i][j] != nullptr){
                printf("tab_wsp[%d][%d] = (%d, %d).\n", i, j, tab_wsp[i][j]->get_x(), tab_wsp[i][j]->get_y());
            }

        }
    }
}