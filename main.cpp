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
/*
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
*/
/*
void get_data(){

    int a; // dlugosc linii
    int b; // liczba tur


    scanf("%d %d\n", &a, &b);

    printf ("\ndane zebrano\na=%d, b=%d \n", a, b);
    // tutaj dzieje sie konstruktor Rozgrywki

    // tymczasowe:

    char tab[10][10000];



    for(int i = 0; i < 6; i++){
        for(int j = 0; j < a; j++) {
            //scanf("%c", &tab[i][j]);
            cin >> tab[i][j];
        }
    }

    printf("\n tablica: \n");
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < a; j++){
            printf("-> %c ", tab[i][j]);
        }
        printf("\n");
        //printf("stuff");
    }



}
*/


int main() {

    // test();
    // test wypisuje nominalne staty

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
    r->wykonaj_ture();
    delete(r);


    return 0;
}