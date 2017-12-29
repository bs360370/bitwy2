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


void test() {

    printf("\n");
    printf("Lucznik:");
    printf("\n");
    Lucznik* l = new Lucznik();
    l->wypisz_wartosci();
    delete (l);

    printf("\n");
    printf("Kusznik:");
    printf("\n");
    Kusznik* q = new Kusznik();
    q->wypisz_wartosci();
    delete (q);

    printf("\n");
    printf("Miecznik:");
    printf("\n");
    Miecznik* m = new Miecznik();
    m->wypisz_wartosci();
    delete (m);

    printf("\n");
    printf("Halabardzista:");
    printf("\n");
    Halabardzista* h = new Halabardzista();
    h->wypisz_wartosci();
    delete (h);

    printf("\n");
    printf("Konny:");
    printf("\n");
    Konny* k = new Konny();
    k->wypisz_wartosci();
    delete (k);

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
    delete (t);

}

void get_data(){

    int* dlugosc_linii = nullptr;
    int* liczba_tur = nullptr;

    scanf ("%d %d\n", dlugosc_linii, liczba_tur);

    for(int i = 0; i<6; i++){

        for(int j = 0; j<dlugosc_linii; j++){

            int znak;
            scanf("%c", znak);
            Rozgrywka.pole[i][j]=znak;

        }

    }




}



int main() {

    // test();
    // test wypisuje nominalne staty


    return 0;
}