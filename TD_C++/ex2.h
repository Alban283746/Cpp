#ifndef EX2_H
#define EX2_H

#include <cmath>
#include <iostream>

class Complex2D {
    double Re;
    double Im;

public:

    Complex2D(double Re = 0.0, double Im = 0.0);
    Complex2D(const Complex2D& c);

    void setR(double r);
    double getR() const;
    void setI(double i);
    double getI() const;

    Complex2D operator+(const Complex2D& b) const;
    Complex2D operator-(const Complex2D& b) const;
    Complex2D operator*(const Complex2D& b) const;
    Complex2D operator/(double t) const;
    Complex2D operator/(const Complex2D& b) const;

    friend Complex2D operator*(double t, const Complex2D& b);
    friend double module(const Complex2D& c);
    friend Complex2D inv(const Complex2D& c);

    bool operator<(const Complex2D& b) const;
    bool operator>(const Complex2D& b) const;

    friend std::ostream& operator<<(std::ostream& os, const Complex2D& c);
};

#endif
