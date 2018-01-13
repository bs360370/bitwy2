

#include <iostream>
#include <ctime>
#include "Oddzial.h"
#include "Rozgrywka.h"

using namespace std;

void generuj_wejscie(int n, char tab[][6]){
    srand(time(NULL));
    //printf("jestem\n");
    int x;
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < n; ++j){
            x = rand() % 9;
            switch(x){
                case(0):{
                    printf("B");
                    tab[j][i] = 'B';
                    break;
                }
                case(1):{
                    printf("H");
                    tab[j][i] = 'H';
                    break;
                }
                case(2):{
                    printf("K");
                    tab[j][i] = 'K';
                    break;
                }
                case(3):{
                    printf("k");
                    tab[j][i] = 'k';
                    break;
                }
                case(4):{
                    printf("L");
                    tab[j][i] = 'L';
                    break;
                }
                case(5):{
                    printf("M");
                    tab[j][i] = 'M';
                    break;
                }
                case(6):{
                    printf("T");
                    tab[j][i] = 'T';
                    break;
                }
                case(7):{
                    printf("X");
                    tab[j][i] = 'X';
                    break;
                }
                default:{
                    printf("X");
                    tab[j][i] = 'X';
                    break;
                }
            }
            if(j != n-1) printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}


void test2(){

}


int main() {

    int dlugosc;                // dlugosc linii
    int tury;                   // liczba tur

    scanf("%d %d", &dlugosc, &tury);

    // printf ("\ndane zebrano\ndlugosc=%d, tury=%d \n", dlugosc, tury);

    char tab[10000][6];

    generuj_wejscie(dlugosc, tab);
/*
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < dlugosc; j++) {
            cin >> tab[j][i];
        }
    }
*/
    Rozgrywka* r = new Rozgrywka(dlugosc, tury, tab);
    r->gra();
    //printf("po grze\n");
    delete(r);
    //printf("po delete\n");




    return 0;
}