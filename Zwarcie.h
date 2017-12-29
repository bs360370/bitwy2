//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_ZWARCIE_H
#define BITWY2_ZWARCIE_H


#include "Oddzial.h"

class Zwarcie : public Oddzial{

protected:

    void policz_modifier() override;

public:

    Wspolrzedne szukaj_celu() override;
    void wspieraj() override;
    int atakuj() override;

    Zwarcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale);

};


#endif //BITWY2_ZWARCIE_H