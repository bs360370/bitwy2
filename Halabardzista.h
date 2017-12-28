//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_HALABARDZISTA_H
#define BITWY2_HALABARDZISTA_H


#include "Zwarcie.h"

class Halabardzista : public Zwarcie{



protected:
    void policz_modifier() override;
// modifiery zależne od przeciwnika
// (np. bonus za atakowanie konkretnego typu)


public:
    char podaj_typ() override;
    void wspieraj() override;
    Wspolrzedne szukaj_celu() override;
    int atakuj() override;

Halabardzista();


};


#endif //BITWY2_HALABARDZISTA_H
