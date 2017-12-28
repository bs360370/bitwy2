//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_BEBNIARZ_H
#define BITWY2_BEBNIARZ_H


#include "Wsparcie.h"

class Bebniarz : public Wsparcie{
protected:
    void policz_modifier();
// modifiery zależne od przeciwnika
// (np. bonus za atakowanie konkretnego typu)


public:
    char podaj_typ();
// konstruktory:
// Miecznik(): Zwarcie(30,20,50,...){}
public:

    void wspieraj();

// zwieksza morale celu
};


#endif //BITWY2_BEBNIARZ_H
