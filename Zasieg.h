

#ifndef BITWY2_ZASIEG_H
#define BITWY2_ZASIEG_H


#include "Oddzial.h"

class Zasieg : public Oddzial{

protected:

    void policz_modifier() override;

public:

    void wspieraj() override;
    int atakuj() override;

    Zasieg(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, int morale, int x, int y, Rozgrywka* rozgrywka);

};


#endif //BITWY2_ZASIEG_H
