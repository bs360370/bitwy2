//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_MIECZNIK_H
#define BITWY2_MIECZNIK_H


#include "Zwarcie.h"

class Miecznik : public Zwarcie{

protected:

    void policz_modifier() override;

public:

    char podaj_typ() override;
    void wspieraj() override;
    Wspolrzedne szukaj_celu() override;
    int atakuj() override;

    Miecznik();

};


#endif //BITWY2_MIECZNIK_H
