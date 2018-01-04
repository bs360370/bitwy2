

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

    Oddzial*** pole;                // macierz polozenia oddzialow
    Wspolrzedne*** tab_wsp;         // macierz do trzymania wspolrzednych celow
    double** tab_atak;              // macierz do trzymania wartosci ataku na dany oddzial

private:
    void resetuj_oddzialy();        // resetuje modifiery z poprzedniej tury
    void policz_cele();             // każe oddziałom znaleźć cele
    void policz_wsparcie();         // każe oddziałom wykonać akcję wsparcia
    void policz_straty();           // każe oddziałom wykonać atak, liczy straty, nakłada straty na oddziały
    void poprzesuwaj();             // pod koniec tury - sprawdza, czy coś umarło i jeśli tak to odpowiednio przestawia

public:

    void wypisz();                  // NARAZIE WYPISUJE STATY - MA WYPISYWAC TO CO MA BYC NA WYJSCIU
    void wykonaj_ture();            // wykonanie wszystkich zadań jednej tury
    void czy_koniec_gry();          // sprawdza, czy któraś armia przegrała

// poza tym metody wywoływane przez Oddział
// jeszcze nie ustalone

// konstruktory, destruktory

    Rozgrywka(int rozmiar, int limit_tur, char tab[][6]);
    ~Rozgrywka();

};


#endif //BITWY2_ROZGRYWKA_H
