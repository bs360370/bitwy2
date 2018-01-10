

#ifndef BITWY2_ZWARCIE_H
#define BITWY2_ZWARCIE_H


#include "Oddzial.h"

class Zwarcie : public Oddzial{

protected:

    void policz_modifier() override;
    void policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) override;

public:

    void wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) override;

    Zwarcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y, Rozgrywka* rozgrywka);
};


#endif //BITWY2_ZWARCIE_H
