

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
    //printf("jestem a akt_wsp\n");
    polozenie->set_x(x);
    //printf("jestem a akt_wsp x\n");
    polozenie->set_y(y);
    //printf("jestem a akt_wsp y\n");
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
        // TODO: tymczasowo liczebnosc
        //printf(" (%d,%d) ", polozenie->get_x(), polozenie->get_y());
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

void Oddzial::otrzymaj_wsparcie(double atak, double obrona, double morale, double morale_cooldown) {
    modifier_atak *= atak;
    modifier_obrona *= obrona;
    modifier_morale *= morale;
    modifier_morale_cooldown *= morale_cooldown;
}

void Oddzial::wypisz_modifiery() {
    printf("(%d,%d) mod_ata = %.2f, ", polozenie->get_x(), polozenie->get_y(), modifier_atak);
    printf("(%d,%d) mod_mor = %.2f, ", polozenie->get_x(), polozenie->get_y(), modifier_morale);
    printf("(%d,%d) mod_obr = %.2f, ", polozenie->get_x(), polozenie->get_y(), modifier_obrona);
    printf("(%d,%d) mod_m_c = %.2f, ", polozenie->get_x(), polozenie->get_y(), modifier_morale_cooldown);
    printf("(%d,%d) akt_lic = %d, ", polozenie->get_x(), polozenie->get_y(), aktualna_liczebnosc);
    printf("(%d,%d) moralee = %.2f\n", polozenie->get_x(), polozenie->get_y(), morale);
}
