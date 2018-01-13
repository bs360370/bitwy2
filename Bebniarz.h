

#ifndef BITWY2_BEBNIARZ_H
#define BITWY2_BEBNIARZ_H


#include "Wsparcie.h"

class Bebniarz : public Wsparcie{

protected:

    void policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) override;

public:

    char podaj_typ() override;
    void wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) override;

    Bebniarz(int x, int y, Rozgrywka* rozgrywka);
};


#endif //BITWY2_BEBNIARZ_H
