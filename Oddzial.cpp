

#include "Oddzial.h"
#include "Rozgrywka.h"
#include <cstdio>
#include <cmath>

using namespace std;

Oddzial::Oddzial(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y, Rozgrywka* rozgr) {
    this->sila_ataku = sila_ataku;
    this->obrona = obrona;
    this->wytrzymalosc = wytrzymalosc;
    this->zasieg = zasieg;
    this->liczebnosc = liczebnosc;
    this->aktualna_liczebnosc = liczebnosc;
    this->morale = morale;
    this->polozenie = new Wspolrzedne(x, y);
    this->wskaznik_na_Rozgrywke = rozgr;
}

Oddzial::~Oddzial() {
    delete (polozenie);
}

void Oddzial::resetuj_modifiery() {
    modifier_atak = 1;
    modifier_morale = 1;
    modifier_obrona = 1;
    modifier_morale_cooldown = 1;
}

Wspolrzedne *Oddzial::szukaj_celu(Oddzial ***p, int ro) {

    int linia = polozenie->get_x();
    int rzad = polozenie->get_y();
    printf(" x = %d, y = %d \n", linia, rzad);
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

    for(int j = 0; j < zasieg; ++j){
        if(rzad-j >= 0 && rzad+j < ro){
            if(j==0){
                if(p[at][rzad] != nullptr){
                    return p[at][rzad]->get_polozenie();
                }
            }
            else {
                if(p[at][rzad-j] != nullptr){
                    return p[at][rzad-j]->get_polozenie();
                }
                if(p[at][rzad+j] != nullptr){
                    return p[at][rzad+j]->get_polozenie();
                }
            }
        }
    }
// TODO: moze powinien returnowac jakies (-1,-1), zeby rozgrywka wiedziala, że ma nie wywolywac ataku dla oddzalu ktory nic nie znajdzie
    printf("Nie znaleziono celu dla oddzialu z pozycji %d, %d\n", polozenie->get_x(), polozenie->get_y());
    return nullptr;
}

double Oddzial::policz_atak() {
    return (1+(sila_ataku*modifier_atak))*(aktualna_liczebnosc);
}

double Oddzial::policz_straty(double obrazenia) {

    double m;
    if(1-morale*modifier_morale){
        m = 1 - (morale*modifier_morale/(1-morale*modifier_morale));
    }
    else m = 1; // TODO: roboczo
    // TODO: cos tu niedziala
    double obr = obrazenia;
    double licznik = obr*m;
    double mianownik = wytrzymalosc*(1+obrona*modifier_obrona);
    double a;

    if(mianownik){
        a = floor(licznik/mianownik);
        if(a > 0){
            return a;
        }
        else return 0;
    }
}

void Oddzial::aktualizuj_liczebnosc(double straty) {
    // TODO: pomyslec co z tym duble i int
    if(straty < aktualna_liczebnosc){
        aktualna_liczebnosc = aktualna_liczebnosc - straty;
    }
    else {
        aktualna_liczebnosc = 0;
    }
}

void Oddzial::aktualizuj_wspolrzedne(int x, int y) {
    printf("jestem a akt_wsp\n");
    polozenie->set_x(x);
    printf("jestem a akt_wsp x\n");
    polozenie->set_y(y);
    printf("jestem a akt_wsp y\n");
}

void Oddzial::aktualizuj_morale(double strata) {
    if(aktualna_liczebnosc){
        morale = morale - modifier_morale_cooldown*(strata/aktualna_liczebnosc);
    }
}

void Oddzial::aktualizuj_morale_2() {
    double maks = std::fmax(0.25, 0.25*abs(morale));
    morale = morale - maks*modifier_morale_cooldown;
}

void Oddzial::wypisz_status() {
    char typ = this->podaj_typ();
    // TODO: w rozgrywce jest drugi raz sprawdzne czy pusty oddzial
    if(aktualna_liczebnosc){
        printf("%c:", typ);
        this->procent_zycia();
        printf(" (%d,%d) ", polozenie->get_x(), polozenie->get_y());
    }
    else {
        printf("  X  ");
    }

}

void Oddzial::procent_zycia() {
    int procent;
    double pro = 100*aktualna_liczebnosc/liczebnosc ;
    procent = (int) floor(pro);
    // TODO: nie wiem czy to jest dobrze ten casting

    if(liczebnosc == aktualna_liczebnosc){
        printf("00");
    }
    if(aktualna_liczebnosc < liczebnosc){
        if(procent >= 10){
            printf("%d", procent);
        }
        if(procent < 10){
            printf("0%d", procent);
        }
    }
    else if(aktualna_liczebnosc > liczebnosc){
        printf("BLAD! liczebnosc wieksza niz nominalna! \n\n");
    }

}

bool Oddzial::czy_konny() {
    return false;
}

bool Oddzial::czy_zasieg() {
    return false;
}

bool Oddzial::czy_martwy() {
    return aktualna_liczebnosc == 0;
}

Wspolrzedne *Oddzial::get_polozenie() {
    return polozenie;
}

void Oddzial::wypisz_wartosci() {
    printf("sila ataku: %d\n obrona: %d\n wytrzymalosc: %d\n zasieg: %d\n liczebnosc: %d\n morale: %lf\n ",
           this->sila_ataku,
           this->obrona,
           this->wytrzymalosc,
           this->zasieg,
           this->liczebnosc,
           this->morale);
}