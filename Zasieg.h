//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_ZASIEG_H
#define BITWY2_ZASIEG_H


#include "Oddzial.h"

class Zasieg : public Oddzial{

protected:

    void policz_modifier() override;

public:

    Wspolrzedne szukaj_celu() override;
    void wspieraj() override;
    int atakuj() override;

    Zasieg(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale);

};


#endif //BITWY2_ZASIEG_H
