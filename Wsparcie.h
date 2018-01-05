

#ifndef BITWY2_WSPARCIE_H
#define BITWY2_WSPARCIE_H


#include "Oddzial.h"

class Wsparcie : public Oddzial {

protected:

    void policz_modifier() override;

public:

    Wspolrzedne* szukaj_celu(Oddzial*** p) override;
    void wspieraj() override;
    int atakuj() override;

    Wsparcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale, int x, int y, Rozgrywka* rozgrywka);

};


#endif //BITWY2_WSPARCIE_H
