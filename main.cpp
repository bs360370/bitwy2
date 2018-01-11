

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
#include "Rozgrywka.h"

using namespace std;

int main() {

    int dlugosc;                // dlugosc linii
    int tury;                   // liczba tur

    scanf("%d %d\n", &dlugosc, &tury);

    // printf ("\ndane zebrano\ndlugosc=%d, tury=%d \n", dlugosc, tury);

    char tab[10000][6];

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < dlugosc; j++) {
            cin >> tab[j][i];
        }
    }

    Rozgrywka* r = new Rozgrywka(dlugosc, tury, tab);
    r->gra();
    //printf("po grze\n");
    delete(r);
    //printf("po delete\n");

    return 0;
}