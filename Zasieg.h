

#ifndef BITWY2_ZASIEG_H
#define BITWY2_ZASIEG_H


#include "Oddzial.h"

class Zasieg : public Oddzial{

protected:

    void policz_modifier() override;

public:

    void wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) override;
    int atakuj() override;

    virtual bool czy_zasieg() override;

    Zasieg(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y, Rozgrywka* rozgrywka);

};


#endif //BITWY2_ZASIEG_H
