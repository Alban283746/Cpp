#include "ex2.h"

Complex2D::Complex2D(double Re, double Im) : Re(Re), Im(Im) {}

Complex2D::Complex2D(const Complex2D& c) : Re(c.Re), Im(c.Im) {}

void Complex2D::setR(double r) { Re = r; }
double Complex2D::getR() const { return Re; }

void Complex2D::setI(double i) { Im = i; }
double Complex2D::getI() const { return Im; }

Complex2D Complex2D::operator+(const Complex2D& b) const {
    return Complex2D(Re + b.Re, Im + b.Im);
}

Complex2D Complex2D::operator-(const Complex2D& b) const {
    return Complex2D(Re - b.Re, Im - b.Im);
}

Complex2D Complex2D::operator*(const Complex2D& b) const {
    return Complex2D(Re * b.Re - Im * b.Im, Re * b.Im + Im * b.Re);
}

Complex2D Complex2D::operator/(double t) const {
    return Complex2D(Re / t, Im / t);
}

Complex2D Complex2D::operator/(const Complex2D& b) const {
    double denominator = b.Re * b.Re + b.Im * b.Im;
    return Complex2D((Re * b.Re + Im * b.Im) / denominator, 
                     (Im * b.Re - Re * b.Im) / denominator);
}

Complex2D operator*(double t, const Complex2D& b) {
    return Complex2D(t * b.Re, t * b.Im);
}

double module(const Complex2D& c) {
    return std::sqrt(c.Re * c.Re + c.Im * c.Im);
}

Complex2D inv(const Complex2D& c) {
    double denom = c.Re * c.Re + c.Im * c.Im;
    return Complex2D(c.Re / denom, -c.Im / denom);
}

bool Complex2D::operator<(const Complex2D& b) const {
    return module(*this) < module(b);
}

bool Complex2D::operator>(const Complex2D& b) const {
    return module(*this) > module(b);
}

std::ostream& operator<<(std::ostream& os, const Complex2D& c) {
    os << c.Re << (c.Im >= 0 ? " + " : " - ") << std::fabs(c.Im) << "i";
    return os;
}