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
    cout << "������ �������� ��� z1:" << endl;
    cin >> z1;

    cout << "z1: " << z1 << ", ��������: " << z1.value() << endl;
    z1.Reduce();
    cout << "�������� �������� z1: " << z1 << endl;

    cout << "������ �������� ��� z2:" << endl;
    cin >> z2;

    cout << "z2: " << z2 << ", ��������: " << z2.value() << endl;

    // ���������
    z3 = z1 + z2;
    cout << "��������� ��������� z1 � z2: " << z3 << ", ���� ��������: " << z3.value() << endl;

    // ³�������
    z3 = z1 - z2;
    cout << "��������� �������� z1 � z2: " << z3 << ", ���� ��������: " << z3.value() << endl;

    // ��������
    z3 = z1 * z2;
    cout << "��������� �������� z1 � z2: " << z3 << ", ���� ��������: " << z3.value() << endl;


    // ��������� �� ��������� 
    ++z3;
    cout << "ϳ��� ����������� ����������: " << z3 << endl;

    Rational objPostInc = z3++;
    cout << "ϳ��� ������������ ����������: " << z3 << " (���������� ��'���: " << objPostInc << ")" << endl;

    --z3;
    cout << "ϳ��� ����������� ����������: " << z3 << endl;

    Rational objPostDec = z3--;
    cout << "ϳ��� ������������ ����������: " << z3 << " (���������� ��'���: " << objPostDec << ")" << endl;
    }
    catch (const MyException& e) {
        cerr << "MyException caught: "  << endl;
    }
    catch (const MyUnexpectedException* e) {
        cerr << "MyUnexpectedException caught: "<< endl;
    }
    catch (const std::exception e) {
        std::cerr << "���������� �������: " << std::endl;
    }
    return 0;
}
