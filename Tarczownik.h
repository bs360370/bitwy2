

#ifndef BITWY2_TARCZOWNIK_H
#define BITWY2_TARCZOWNIK_H

#include "Wsparcie.h"

class Tarczownik : public Wsparcie{

protected:

    void policz_modifier(Oddzial*** tab1, Wspolrzedne*** tab2) override;

public:

    char podaj_typ() override;
    void wspieraj(Oddzial*** tab1, Wspolrzedne*** tab2) override;

    Tarczownik(int x, int y, Rozgrywka* rozgrywka);
    ~Tarczownik() override = default;
};


#endif //BITWY2_TARCZOWNIK_H
