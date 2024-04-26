// Rational.h
#pragma once
#include <iostream>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

public:
    Rational();
    Rational(int a, int b);
    Rational(const Rational& other);
    ~Rational();

    double GetA() const { return numerator; }
    double GetB() const { return denominator; }
    void SetA(int value);
    void SetB(int value);

    void Reduce();
    double value() const;

    friend Rational operator+(const Rational& l, const Rational& r);
    friend Rational operator-(const Rational& l, const Rational& r);
    friend Rational operator*(const Rational& l, const Rational& r);

    Rational& operator=(const Rational& other);
    operator string () const;
    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator--(int);

    friend ostream& operator<<(ostream& out, const Rational& rational);
    friend istream& operator>>(istream& in, Rational& rational);
};
