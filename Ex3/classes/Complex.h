// Complex.h
#pragma once
#include <iostream>

class Complex {
public:
    double Re, Im;

    Complex(double re = 0, double im = 0) : Re(re), Im(im) {}

    Complex operator +(const Complex& c) const {
        return Complex(Re + c.Re, Im + c.Im);
    }

    Complex operator -(const Complex& c) const {
        return Complex(Re - c.Re, Im - c.Im);
    }

    Complex operator *(const Complex& c) const {
        return Complex(Re * c.Re - Im * c.Im, Re * c.Im + Im * c.Re);
    }

    Complex operator /(const Complex& c) const {
        double denominator = c.Re * c.Re + c.Im * c.Im;
        return Complex((Re * c.Re + Im * c.Im) / denominator, (Im * c.Re - Re * c.Im) / denominator);
    }

    Complex Conjugate() const {
        return Complex(Re, -Im);
    }

    double Mod() const {
        return sqrt(Re * Re + Im * Im);
    }

    double Arg() const {
        if (Mod() == 0) return 0;
        if (Re > 0) return atan(Im / Re);
        if (Re < 0) return Im >= 0 ? acos(-1) + atan(Im / Re) : -acos(-1) - atan(Im / Re);
        return Im > 0 ? acos(0) : -acos(0);
    }

    friend std::ostream& operator<<(std::ostream& o, const Complex& c) {
        return o << '(' << c.Re << ", " << c.Im << ')';
    }
};
