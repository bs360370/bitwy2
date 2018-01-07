

#ifndef BITWY2_BEBNIARZ_H
#define BITWY2_BEBNIARZ_H


#include "Wsparcie.h"

class Bebniarz : public Wsparcie{

protected:

    void policz_modifier() override;

public:

    char podaj_typ() override;
    void wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) override;
    int atakuj() override;

    Bebniarz(int x, int y, Rozgrywka* rozgrywka);

};


#endif //BITWY2_BEBNIARZ_H
