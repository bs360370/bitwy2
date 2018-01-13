

#ifndef BITWY2_ROZGRYWKA_H
#define BITWY2_ROZGRYWKA_H


#include "Wspolrzedne.h"

class Oddzial;

class Rozgrywka {

// klasa Rozgrywka zarządza przebiegiem rozgrywki
// i wypisywaniem wyniku

private:

    int rozmiar;                    // 2N
    int limit_tur;                  // T

    int aktualna_tura = 0;          // licznik tur od 0 to T (na potrzeby wypisywania wyjscia)

    Oddzial*** pole;                // macierz polozenia oddzialow (trzyma wskazniki na oddzialy)
    Wspolrzedne*** tab_wsp;         // macierz do trzymania wspolrzednych celow
    double** tab_strat_licz;        // macierz do trzymania wartosci strat liczebnosci

    // TODO: dodaj reset tab_wsp i tab_strat_licz ? (chyba jest nie potrzebny o itak w kazdej turze sie nadpisuje - ale pomyslec)

 // TODO: ustalic co ma byc public a co nie (narazie na potrzeby testowania jest wszystko public)

    void resetuj_oddzialy();        // resetuje modifiery z poprzedniej tury
    void policz_cele();             // każe oddziałom znaleźć cele
    void policz_modifiery();
    void policz_wsparcie();         // każe oddziałom wykonać akcję wsparcia
    void policz_atak();             // liczy obrazenia oddzialu, strate celu do tab_strat_licz, pojedyncze straty morale
    void policz_straty_licz();      // zmniejsza liczebnosci oddzialow, zmiensza morale sasiadujacych oddzialow jesli cos umarlo
    void poprzesuwaj_1();           // przesuwa oddzialy do linii pomiedzy armiami
    void poprzesuwaj_2();           // przesuwa kolumny do N-tej az nie bedzie dziur

    void wypisz_tab_wsp();          // funkcja pomocnicza - wypisuje tab_wsp

    bool czy_koniec_gry();          // sprawdza, czy któraś armia przegrała

    void wykonaj_ture();            // wykonanie wszystkich zadań jednej tury
    void wypisz_ture();             // wypisuje stan pola w danej turze // TODO: poprawić, bo nie wypisuje ostatniej tury

    void wypisz();                  // funkcja pomocznicza - wypisuje poctkowe staty danego typu jenostki

    void wypisz_modifiery();        // funkcja pomocnicza

public:
    void gra();                     // wykonuje limit_tur tur\

// konstruktory, destruktory

    Rozgrywka(int rozmiar, int limit_tur, char tab[][6]);
    ~Rozgrywka();

};

#endif //BITWY2_ROZGRYWKA_H
