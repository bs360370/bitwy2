

#ifndef BITWY2_ODDZIAL_H
#define BITWY2_ODDZIAL_H


#include "Wspolrzedne.h"
#include <cstring>

class Rozgrywka;

class Oddzial {

protected:

    int sila_ataku;
    int obrona;
    int wytrzymalosc;
    int zasieg;

    Rozgrywka* wskaznik_na_Rozgrywke;   // TODO: zobaczyć, czy jest potrzebny


public:

    Wspolrzedne* polozenie;

    int liczebnosc;
    double morale;

    int aktualna_liczebnosc;                                                    // kiedy spadnie do zera oddzial umiera

    // modifiery sluza do opisu kar, bonusów i wartosci wsparcia na poszczegolne oddzialy

    double modifier_atak;
    double modifier_morale;
    double modifier_obrona;
    double modifier_morale_cooldown;

    void resetuj_modifiery();                                                   // ustawia modifiery danego odzialu na 1 (modifiery są domnazane)
    virtual Wspolrzedne* szukaj_celu(Oddzial*** p, int ro) = 0;                     // szukanie celu [override w Luczniku i Wsparciu]
    virtual void policz_modifier() = 0;                                         // liczenie podifierow dla ... // TODO: dopisac reszte komentarza
    virtual void policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) = 0;     // liczenie modifierow dla ... // TODO: dopisac reszte komentarza
    virtual bool czy_konny();                                                   // dla Konnego zwraca true, w reszice false - potrzebne do liczenia bonusów
    virtual bool czy_zasieg();                                                  // dla Zwarcia zwraca true, dla reszty false - potrzebne do liczenia bonusów
    virtual void wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) = 0;            // liczy wsparcie w jednostkach wsparcia, w innych nic nie robi
    double policz_atak();                                                       // liczy wartosc obrazen zadawanych przez dana jednostke
    double policz_straty(double obrazenia);                                     // liczy straty ponoszone przez cel w zaleznosci od wartosci obrazen atakujacego
    void aktualizuj_liczebnosc(double straty);                                  // odejmuje straty od aktualna_liczebnosc w kazdej turze
    void aktualizuj_wspolrzedne(int x, int y); // TODO: nie wiem czy ta funkcja jest gdziekoleik uzywana
    void aktualizuj_morale(double strata);                                      // strata morale przy pojedynczym ataku na oddzial
    void aktualizuj_morale_2();                                                 // strata morale po smierci oddzialu // TODO: cos nie dziala

    void procent_zycia();                                                       // wypisuje procent zycia na wyjsciu
    void wypisz_status();                                                       // wypsiuje np: K:43 na wyjsciu dla danego typu oddzialu typ i procent zycia

    virtual char podaj_typ() = 0;                                               // w zaleznosci od typu jednostki zwraca literke typu (char)
    Wspolrzedne* get_polozenie();                                               // geter polozenia

    bool czy_martwy(); // TODO: nie wiem czy to jest gdzies uzyte

    // konstruktory, destruktory

    Oddzial(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y, Rozgrywka* rozgr);
    ~Oddzial();

    void wypisz_wartosci();                                                     // funkcja pomocnicza - wypisuje staty
};


#endif //BITWY2_ODDZIAL_H
