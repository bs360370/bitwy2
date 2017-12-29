//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_TARCZOWNIK_H
#define BITWY2_TARCZOWNIK_H


#include "Wsparcie.h"

class Tarczownik : public Wsparcie{

protected:

    void policz_modifier() override;

public:

    char podaj_typ() override;
    void wspieraj() override;
    Wspolrzedne szukaj_celu() override;
    int atakuj() override;

    Tarczownik();

};


#endif //BITWY2_TARCZOWNIK_H
