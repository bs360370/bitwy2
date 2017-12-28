//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_HALABARDZISTA_H
#define BITWY2_HALABARDZISTA_H


#include "Zwarcie.h"

class Halabardzista : public Zwarcie{
protected:
    void policz_modifier();
// modifiery zależne od przeciwnika
// (np. bonus za atakowanie konkretnego typu)


public:
    char podaj_typ();
// konstruktory:
// Miecznik(): Zwarcie(30,20,50,...){}
};


#endif //BITWY2_HALABARDZISTA_H
