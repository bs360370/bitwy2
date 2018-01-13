

#ifndef BITWY2_KONNY_H
#define BITWY2_KONNY_H


#include "Zwarcie.h"

class Konny : public Zwarcie{

protected:

    void policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) override;

public:

    char podaj_typ() override;
    void wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) override;
    bool czy_konny() override;

    Konny(int x, int y, Rozgrywka* rozgrywka);
};


#endif //BITWY2_KONNY_H
