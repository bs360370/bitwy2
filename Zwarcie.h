

#ifndef BITWY2_ZWARCIE_H
#define BITWY2_ZWARCIE_H


#include "Oddzial.h"

class Zwarcie : public Oddzial{

protected:

    void policz_modifier() override;

public:

    void wspieraj() override;
    int atakuj() override;

    Zwarcie(int sila_ataku, int obrona, int wytrzymalosc, int zasieg, int liczebnosc, double morale, int x, int y, Rozgrywka* rozgrywka);

};


#endif //BITWY2_ZWARCIE_H
