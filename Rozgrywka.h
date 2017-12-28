//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_ROZGRYWKA_H
#define BITWY2_ROZGRYWKA_H


#include "Oddzial.h"

class Rozgrywka {
private:
// klasa Rozgrywka zarządza przebiegiem rozgrywki
// i wypisywaniem wyniku

    Oddzial* pole;    // macierz 7 na 2N
    int rozmiar;               // 2N
    int limit_tur;              // T

    void resetuj_oddzialy();
    // resetuje modifiery z poprzedniej tury
    void policz_cele();
    // każe oddziałom znaleźć cele
    void policz_wsparcie();
    // każe oddziałom wykonać akcję wsparcia
    void policz_straty();
    // każe oddziałom wykonać atak
    // liczy straty
    // nakłada straty na oddziały
    void poprzesuwaj();
    // pod koniec tury - sprawdza, czy coś umarło
    // i jeśli tak to odpowiednio przestawia

public:

    void wypisz();
    // wypisanie wyniku jednej tury
    void wykonaj_ture();
    // wykonanie wszystkich zadań jednej tury
    void czy_koniec_gry();
    // sprawdza, czy któraś armia przegrała

// poza tym metody wywoływane przez Oddział
// jeszcze nie ustalone
// konstruktory, destruktory
};


#endif //BITWY2_ROZGRYWKA_H
