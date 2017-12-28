#include <iostream>
#include "Oddzial.h"
#include "Wsparcie.h"

int main() {

    Wsparcie* x = new Wsparcie();

    std::cout << "Hello, World!" << std::endl;

    x->wypisz();

    delete (x);

    return 0;
}