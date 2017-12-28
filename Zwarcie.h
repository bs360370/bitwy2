//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_ZWARCIE_H
#define BITWY2_ZWARCIE_H


#include "Oddzial.h"

class Zwarcie : public Oddzial{
protected:

    void policz_modifier();
    // modifiery odpowiednie dla zwarcia

public:

    // konstruktory:
    // Zwarcie(int sila, int...): Oddzial (sila, ...){}
    Wspolrzedne szukaj_celu();
    // dla Wsparcia szukanie celu jest inne
    // (szuka celu w swojej armii)
    void wspieraj();
    // w Zwarciu nie robi nic
    // robi coś tylko we Wsparciu
    int atakuj();
    // we Wsparciu nie robi nic
    // w pozostałych liczy modifier i atak
};


#endif //BITWY2_ZWARCIE_H
