

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
    ~Wspolrzedne() = default;
    Wspolrzedne (const Wspolrzedne&) = delete;
    Wspolrzedne& operator=(const Wspolrzedne&) = delete;
};


#endif //BITWY2_WSPOLRZEDNE_H
