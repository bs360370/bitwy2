

#ifndef BITWY2_MIECZNIK_H
#define BITWY2_MIECZNIK_H


#include "Zwarcie.h"

class Miecznik : public Zwarcie{

protected:

    void policz_modifier() override;

public:

    char podaj_typ() override;
    void wspieraj() override;
    int atakuj() override;

    Miecznik(int x, int y, Rozgrywka* rozgrywka);

};


#endif //BITWY2_MIECZNIK_H
