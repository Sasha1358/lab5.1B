#include "Rational.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
#include "MyUnexpectedException.h"
#include "MyException.h"

using namespace std;

Rational::Rational() : numerator(0), denominator(1) {}
Rational::Rational(int a, int b) : numerator(a), denominator(b) {
    if ( b == 0) {
        throw MyUnexpectedException(" Denominator are zero.");
    }
    Reduce();
}
Rational::Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator) {}
Rational::~Rational() {}

void Rational::Reduce() {
    int gcd = 1;
    int smaller = (numerator < denominator) ? numerator : denominator;

    for (int i = 2; i <= smaller; ++i) {
        if (numerator % i == 0 && denominator % i == 0) {
            gcd = i;
        }
    }

    if (gcd > 1) {
        numerator /= gcd;
        denominator /= gcd;
    }
}
void Rational::SetA(int value) {
    numerator = value;
}
void Rational::SetB(int value) {
    denominator = value;
}

ostream& operator<<(ostream& out, const Rational& rational) {
    out << rational.GetA() << "\\" << rational.GetB();
    return out;
}
istream& operator>>(istream& in, Rational& rational) {
    int a, b;
    std::string input_a, input_b;
    in >> input_a >> input_b;

    try {
        a = std::stoi(input_a);
        b = std::stoi(input_b);
    }
    catch (const std::invalid_argument& e) {
        const char* errorMsg = "Invalid input. Please enter valid numbers.";
        int size = MultiByteToWideChar(CP_UTF8, 0, errorMsg, -1, NULL, 0);
        wchar_t* wideMsg = new wchar_t[size];
        MultiByteToWideChar(CP_UTF8, 0, errorMsg, -1, wideMsg, size);
        MessageBox(NULL, wideMsg, L"Error", MB_ICONERROR | MB_OK);
        delete[] wideMsg;
        throw MyException("Invalid input. Please enter valid numbers.");
    }

    try {
        if (b == 0) {
            const char* errorMsg = "Division by zero is not allowed.";
            int size = MultiByteToWideChar(CP_UTF8, 0, errorMsg, -1, NULL, 0);
            wchar_t* wideMsg = new wchar_t[size];
            MultiByteToWideChar(CP_UTF8, 0, errorMsg, -1, wideMsg, size);
            MessageBox(NULL, wideMsg, L"Error", MB_ICONERROR | MB_OK);
            delete[] wideMsg;
            throw MyUnexpectedException("Division by zero is not allowed.");
        }
        rational.SetA(a);
        rational.SetB(b);
        rational.Reduce();
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    return in;
}

Rational& Rational::operator=(const Rational& other) {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}
Rational::operator std::string() const {
    std::ostringstream oss;
    oss << "A = " << numerator << ", B = " << denominator;
    return oss.str();
}

Rational& Rational::operator++() {
    numerator += denominator;
    Reduce();
    return *this;
}
Rational Rational::operator++(int) {
    Rational temp = *this;
    numerator += denominator;
    Reduce();
    return temp;
}
Rational& Rational::operator--() {
    numerator -= denominator;
    Reduce();
    return *this;
}
Rational Rational::operator--(int) {
    Rational temp = *this;
    numerator -= denominator;
    Reduce();
    return temp;
}

Rational operator+(const Rational& l, const Rational& r) {
    return Rational(l.numerator * r.denominator + r.numerator * l.denominator,
        l.denominator * r.denominator);
}
Rational operator-(const Rational& l, const Rational& r) {
    return Rational(l.numerator * r.denominator - r.numerator * l.denominator,
        l.denominator * r.denominator);
}
Rational operator*(const Rational& l, const Rational& r) {
    return Rational(l.numerator * r.numerator, l.denominator * r.denominator);
}
double Rational::value() const {

    if (denominator == 0) {
        throw MyUnexpectedException(" Denominator are zero.");
    }
    return static_cast<double>(numerator) / denominator;
}
