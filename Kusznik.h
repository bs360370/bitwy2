//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_KUSZNIK_H
#define BITWY2_KUSZNIK_H


#include "Zasieg.h"

class Kusznik : public Zasieg{
protected:
    void policz_modifier();
// modifiery zależne od przeciwnika
// (np. bonus za atakowanie konkretnego typu)


public:
    char podaj_typ();
// konstruktory:
// Miecznik(): Zwarcie(30,20,50,...){}
};


#endif //BITWY2_KUSZNIK_H
