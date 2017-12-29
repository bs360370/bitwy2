//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_KUSZNIK_H
#define BITWY2_KUSZNIK_H


#include "Zasieg.h"

class Kusznik : public Zasieg{

protected:

    void policz_modifier() override;

public:

    char podaj_typ() override;
    void wspieraj() override;
    Wspolrzedne szukaj_celu() override;
    int atakuj() override;

    Kusznik();

};


#endif //BITWY2_KUSZNIK_H