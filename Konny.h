//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_KONNY_H
#define BITWY2_KONNY_H


#include "Zwarcie.h"

class Konny : public Zwarcie{

protected:

    void policz_modifier() override;

public:

    char podaj_typ() override;
    void wspieraj() override;
    Wspolrzedne szukaj_celu() override;
    int atakuj() override;

    Konny();

};


#endif //BITWY2_KONNY_H
