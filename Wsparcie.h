

#ifndef BITWY2_WSPARCIE_H
#define BITWY2_WSPARCIE_H


#include "Oddzial.h"

class Wsparcie : public Oddzial {

protected:

    void policz_modifier() override;
    void policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) override;

public:

    Wspolrzedne* szukaj_celu(Oddzial*** p, int ro) override;
    void wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) override;
    int atakuj() override;

    Wsparcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y, Rozgrywka* rozgrywka);

};


#endif //BITWY2_WSPARCIE_H
