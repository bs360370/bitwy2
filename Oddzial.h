

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




    Rozgrywka* wskaznik_na_Rozgrywke;
    Wspolrzedne* polozenie;






public:

    int aktualna_liczebnosc;
    double modifier_atak;
    double modifier_morale;
    double modifier_obrona;
    double modifier_morale_cooldown;
    int liczebnosc;
    double morale;

    virtual void policz_modifier() = 0;
    virtual void policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) = 0;
    double policz_atak();
    double policz_straty(double obrazenia);
    void procent_zycia();
    void wypisz_status();
    Wspolrzedne* get_polozenie();
    void resetuj_modifiery();
    virtual char podaj_typ() = 0;
    virtual Wspolrzedne* szukaj_celu(Oddzial*** p, int ro);
    virtual void wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) = 0;
    virtual int atakuj() = 0;
    void aktualizuj_liczebnosc(double straty);
    void aktualizuj_wspolrzedne(int x, int y); // TODO: ...
    void aktualizuj_morale(double strata);
    void aktualizuj_morale_2(); // TODO: strata morale po smierci oddzialu
    bool czy_martwy(); // TODO: nie wiem czy to potrzebne teraz

    virtual bool czy_konny();
    virtual bool czy_zasieg();

    Oddzial(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y, Rozgrywka* rozgr);
    ~Oddzial();

    void wypisz_wartosci();     // wypisuje staty
};


#endif //BITWY2_ODDZIAL_H
