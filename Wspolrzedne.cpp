

#include "Wspolrzedne.h"

Wspolrzedne::Wspolrzedne(int x, int y): x(x), y(y){

}

int Wspolrzedne::get_x() {
    return x;
}

int Wspolrzedne::get_y() {
    return y;
}

void Wspolrzedne::set_x(int x) {
    this->x = x;
}

void Wspolrzedne::set_y(int y) {
    this->y = y;
}