

#include <iostream>
#include <ctime>
#include "Oddzial.h"
#include "Rozgrywka.h"

using namespace std;

void generuj_wejscie(int n, char tab[][6]){
    srand(time(NULL));
    int x;

    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < n; ++j){
            x = rand() % 9;
            switch(x){
                case(0):{
                    cout << "B";
                    tab[j][i] = 'B';
                    break;
                }
                case(1):{
                    cout << "H";
                    tab[j][i] = 'H';
                    break;
                }
                case(2):{
                    cout << "K";
                    tab[j][i] = 'K';
                    break;
                }
                case(3):{
                    cout << "k";
                    tab[j][i] = 'k';
                    break;
                }
                case(4):{
                    cout << "L";
                    tab[j][i] = 'L';
                    break;
                }
                case(5):{
                    cout << "M";
                    tab[j][i] = 'M';
                    break;
                }
                case(6):{
                    cout << "T";
                    tab[j][i] = 'T';
                    break;
                }
                case(7):{
                    cout << "X";
                    tab[j][i] = 'X';
                    break;
                }
                default:{
                    cout << "X";
                    tab[j][i] = 'X';
                    break;
                }
            }
            if(j != n-1) cout << " ";;
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    int dlugosc;                // dlugosc linii
    int tury;                   // liczba tur

    cin >> dlugosc >> tury;

    char tab[10000][6];

    // generuj_wejscie(dlugosc, tab);   // alternatywne wejście

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < dlugosc; j++) {
            cin >> tab[j][i];
        }
    }

    Rozgrywka* r = new Rozgrywka(dlugosc, tury, tab);
    r->gra();
    delete(r);

    // komentarz

    return 0;
}