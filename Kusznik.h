

#ifndef BITWY2_KUSZNIK_H
#define BITWY2_KUSZNIK_H


#include "Zasieg.h"

class Kusznik : public Zasieg{

protected:

    void policz_modifier() override;

public:

    char podaj_typ() override;
    void wspieraj() override;
    int atakuj() override;

    Kusznik(int x, int y, Rozgrywka* rozgrywka);

};


#endif //BITWY2_KUSZNIK_H
