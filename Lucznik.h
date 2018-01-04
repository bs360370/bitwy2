

#ifndef BITWY2_LUCZNIK_H
#define BITWY2_LUCZNIK_H


#include "Zasieg.h"

class Lucznik : public Zasieg{

protected:

    void policz_modifier() override;

public:

    char podaj_typ() override;
    void wspieraj() override;
    Wspolrzedne szukaj_celu() override;
    int atakuj() override;

    Lucznik(int x, int y, Rozgrywka* rozgrywka);

};


#endif //BITWY2_LUCZNIK_H
