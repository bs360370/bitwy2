#include <iostream>
#include "Oddzial.h"

int main() {

    Oddzial* x = new Oddzial();

    std::cout << "Hello, World!" << std::endl;

    x->wypisz();

    delete (x);

    return 0;
}