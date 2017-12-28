//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_LUCZNIK_H
#define BITWY2_LUCZNIK_H


#include "Zasieg.h"

class Lucznik : public Zasieg{

    const int sila_ataku;
    const int obrona;
    const int wytrzymalosc;
    const int zasieg;
    int liczebnosc;
    int morale;

protected:
    void policz_modifier() override;
// modifiery zależne od przeciwnika
// (np. bonus za atakowanie konkretnego typu)


public:
    char podaj_typ() override;
    void wspieraj() override;
    Wspolrzedne szukaj_celu() override;
    int atakuj() override;
};


#endif //BITWY2_LUCZNIK_H
