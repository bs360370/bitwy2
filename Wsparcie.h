//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_WSPARCIE_H
#define BITWY2_WSPARCIE_H


#include "Oddzial.h"

class Wsparcie : public Oddzial {
protected:

    void policz_modifier() override;

public:

    Wsparcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale);

    Wspolrzedne szukaj_celu() override;
    void wspieraj() override;
    int atakuj() override;
};


#endif //BITWY2_WSPARCIE_H
