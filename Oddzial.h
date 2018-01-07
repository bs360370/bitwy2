

#ifndef BITWY2_ODDZIAL_H
#define BITWY2_ODDZIAL_H


#include "Wspolrzedne.h"
#include <string.h>

class Rozgrywka;

class Oddzial {

protected:

    int sila_ataku;
    int obrona;
    int wytrzymalosc;
    int zasieg;
    int liczebnosc;
    int morale;

    int aktualna_liczebnosc;

    Rozgrywka* wskaznik_na_Rozgrywke;
    Wspolrzedne* polozenie;

    double modifier_atak;
    double modifier_morale;
    double modifier_obrona;
    virtual void policz_modifier() = 0;





public:

    double policz_atak();
    int policz_straty(double** tab);
    void procent_zycia();
    void wypisz_status();
    Wspolrzedne* get_polozenie();
    void resetuj_modifiery();
    virtual char podaj_typ() = 0;
    virtual Wspolrzedne* szukaj_celu(Oddzial*** p, int ro);
    virtual void wspieraj() = 0;
    void otrzymaj_wsparcie();
    virtual int atakuj() = 0;
    void aktualizuj_liczebnosc();
    void aktualizuj_wspolrzedne(int x, int y);
    void aktualizuj_morale();
    bool czy_martwy();

    Oddzial(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale, int x, int y, Rozgrywka* rozgr);
    ~Oddzial();

    void wypisz_wartosci();                     // wypisuje staty oddzialu zawarte w tresci zadania
};


#endif //BITWY2_ODDZIAL_H
