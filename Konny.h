

#ifndef BITWY2_KONNY_H
#define BITWY2_KONNY_H


#include "Zwarcie.h"

class Konny : public Zwarcie{

protected:

    void policz_modifier() override;

public:

    char podaj_typ() override;
    void wspieraj() override;
    int atakuj() override;

    Konny(int x, int y, Rozgrywka* rozgrywka);

};


#endif //BITWY2_KONNY_H
