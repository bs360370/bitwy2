

#ifndef BITWY2_KUSZNIK_H
#define BITWY2_KUSZNIK_H


#include "Zasieg.h"

class Kusznik : public Zasieg{

protected:

    void policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) override;

public:

    char podaj_typ() override;
    void wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) override;

    Kusznik(int x, int y, Rozgrywka* rozgrywka);
};


#endif //BITWY2_KUSZNIK_H
