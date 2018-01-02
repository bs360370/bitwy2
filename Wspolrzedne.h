//
// Created by Basia on 28.12.2017.
//

#ifndef BITWY2_WSPOLRZEDNE_H
#define BITWY2_WSPOLRZEDNE_H


class Wspolrzedne {
private:
    int x;
    int y;
public:
    int get_x();
    int get_y();
    void set_x(int x);
    void set_y(int y);
    Wspolrzedne(int x, int y);
};


#endif //BITWY2_WSPOLRZEDNE_H
