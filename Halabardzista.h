

#ifndef BITWY2_HALABARDZISTA_H
#define BITWY2_HALABARDZISTA_H


#include "Zwarcie.h"

class Halabardzista : public Zwarcie{

protected:

    void policz_modifier() override;

public:

    char podaj_typ() override;
    void wspieraj() override;
    Wspolrzedne szukaj_celu() override;
    int atakuj() override;

    Halabardzista(int x, int y, Rozgrywka* rozgrywka);

};


#endif //BITWY2_HALABARDZISTA_H
