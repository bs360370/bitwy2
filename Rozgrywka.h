

#ifndef BITWY2_ROZGRYWKA_H
#define BITWY2_ROZGRYWKA_H


#include "Wspolrzedne.h"

class Oddzial;

class Rozgrywka {

// klasa Rozgrywka zarządza przebiegiem rozgrywki
// i wypisywaniem wyniku

public:

    int rozmiar;                    // 2N
    int limit_tur;                  // T

    int aktualna_tura = 0;          // licznik tur od 0 to T

    Oddzial*** pole;                // macierz polozenia oddzialow
    Wspolrzedne*** tab_wsp;         // macierz do trzymania wspolrzednych celow
    double** tab_strat_licz;        // macierz do trzymania wartosci strat liczebnosci


    // TODO: dodaj reset tab_wsp i tab_strat_licz


public:

    void wypisz_tab_wsp();

    void resetuj_oddzialy();        // resetuje modifiery z poprzedniej tury
    void policz_modifiery();
    void policz_cele();             // każe oddziałom znaleźć cele
    void policz_wsparcie();         // każe oddziałom wykonać akcję wsparcia
    void policz_atak();             // liczy obrazenia oddzialu, strate celu do tab_strat_licz, pojedyncze straty morale
    void policz_straty_licz();      // zmniejsza liczebnosci oddzialow, zmiensza morale sasiadujacych oddzialow jesli cos umarlo
    void poprzesuwaj_1();           // przesuwa oddzialy do linii pomiedzy armiami
    void poprzesuwaj_2();           // przesuwa kolumny do N-tej az nie bedzie dziur


public:

    void gra();            // wykonuje limit_tur tur
    void wypisz();                  // NARAZIE WYPISUJE STATY - MA WYPISYWAC TO CO MA BYC NA WYJSCIU
    void wykonaj_ture();            // wykonanie wszystkich zadań jednej tury
    bool czy_koniec_gry();          // sprawdza, czy któraś armia przegrała
    void wypisz_ture();

// poza tym metody wywoływane przez Oddział
// jeszcze nie ustalone

// konstruktory, destruktory

    Rozgrywka(int rozmiar, int limit_tur, char tab[][6]);
    ~Rozgrywka();

};


#endif //BITWY2_ROZGRYWKA_H
