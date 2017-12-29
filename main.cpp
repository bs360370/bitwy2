#include <iostream>
#include "Oddzial.h"
#include "Wsparcie.h"
#include "Halabardzista.h"
#include "Lucznik.h"
#include "Kusznik.h"
#include "Miecznik.h"
#include "Konny.h"
#include "Bebniarz.h"
#include "Tarczownik.h"

int main() {

    printf("\n");
    printf("Lucznik:");
    printf("\n");
    Lucznik* l = new Lucznik();
    l->wypisz_wartosci();

    printf("\n");
    printf("Kusznik:");
    printf("\n");
    Kusznik* q = new Kusznik();
    q->wypisz_wartosci();

    printf("\n");
    printf("Miecznik:");
    printf("\n");
    Miecznik* m = new Miecznik();
    m->wypisz_wartosci();

    printf("\n");
    printf("Halabardzista:");
    printf("\n");
    Halabardzista* h = new Halabardzista();
    h->wypisz_wartosci();

    printf("\n");
    printf("Konny:");
    printf("\n");
    Konny* k = new Konny();
    k->wypisz_wartosci();

    printf("\n");
    printf("Bebniarz:");
    printf("\n");
    Bebniarz* b = new Bebniarz();
    b->wypisz_wartosci();

    printf("\n");
    printf("Tarczownik:");
    printf("\n");
    Tarczownik* t = new Tarczownik();
    t->wypisz_wartosci();

    return 0;
}