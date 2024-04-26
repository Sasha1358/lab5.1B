#include "Rational.h"
#include <iostream>
#include <Windows.h>
#include "MyException.h"
#include "MyUnexpectedException.h"
#include <stdexcept> 
#include <exception>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Rational z1, z2, z3;
    try {
    cout << "Введіть значення для z1:" << endl;
    cin >> z1;

    cout << "z1: " << z1 << ", значення: " << z1.value() << endl;
    z1.Reduce();
    cout << "Зменшене значення z1: " << z1 << endl;

    cout << "Введіть значення для z2:" << endl;
    cin >> z2;

    cout << "z2: " << z2 << ", значення: " << z2.value() << endl;

    // Додавання
    z3 = z1 + z2;
    cout << "Результат додавання z1 і z2: " << z3 << ", його значення: " << z3.value() << endl;

    // Віднімання
    z3 = z1 - z2;
    cout << "Результат віднімання z1 і z2: " << z3 << ", його значення: " << z3.value() << endl;

    // Множення
    z3 = z1 * z2;
    cout << "Результат множення z1 і z2: " << z3 << ", його значення: " << z3.value() << endl;


    // Інкремент та декремент 
    ++z3;
    cout << "Після префіксного інкременту: " << z3 << endl;

    Rational objPostInc = z3++;
    cout << "Після постфіксного інкременту: " << z3 << " (тимчасовий об'єкт: " << objPostInc << ")" << endl;

    --z3;
    cout << "Після префіксного декременту: " << z3 << endl;

    Rational objPostDec = z3--;
    cout << "Після постфіксного декременту: " << z3 << " (тимчасовий об'єкт: " << objPostDec << ")" << endl;
    }
    catch (const MyException& e) {
        cerr << "MyException caught: "  << endl;
    }
    catch (const MyUnexpectedException* e) {
        cerr << "MyUnexpectedException caught: "<< endl;
    }
    catch (const std::exception e) {
        std::cerr << "Стандартна помилка: " << std::endl;
    }
    return 0;
}
