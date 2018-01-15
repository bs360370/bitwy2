

#ifndef BITWY2_ZASIEG_H
#define BITWY2_ZASIEG_H


#include "Oddzial.h"

class Zasieg : public Oddzial{

protected:

    void policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) override;

public:

    Wspolrzedne* szukaj_celu(Oddzial*** p, int ro) override;
    void wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) override;
    bool czy_zasieg() override;

    Zasieg(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y, Rozgrywka* rozgrywka);
    ~Zasieg() override = default;
};


#endif //BITWY2_ZASIEG_H
