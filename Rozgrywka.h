//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_ROZGRYWKA_H
#define BITWY2_ROZGRYWKA_H


class Oddzial;

class Rozgrywka {

// klasa Rozgrywka zarządza przebiegiem rozgrywki
// i wypisywaniem wyniku
public:
    //Oddzial* pole;    // macierz 7 na 2N
    int rozmiar;               // 2N
    int limit_tur;              // T

    Oddzial** pole;



private:
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

    Rozgrywka(int rozmiar, int limit_tur);
    ~Rozgrywka();

};


#endif //BITWY2_ROZGRYWKA_H
