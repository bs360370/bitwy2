

#ifndef BITWY2_LUCZNIK_H
#define BITWY2_LUCZNIK_H


#include "Zasieg.h"

class Lucznik : public Zasieg{

protected:

    void policz_modifier() override;
    void policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) override;

public:

    char podaj_typ() override;
    void wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) override;
    Wspolrzedne* szukaj_celu(Oddzial*** p, int ro) override;

    Lucznik(int x, int y, Rozgrywka* rozgrywka);
};


#endif //BITWY2_LUCZNIK_H
