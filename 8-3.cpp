#include <iostream>
using namespace std;

class Complex {
public:
    //CONSTRUCTORS
    Complex(double r);  //sets real number to r and imaginary number to 0
    Complex(double r, double i);  //sets two supplied values to
    //real and imaginary numbers
    Complex();
    //sets both real and imaginary numbers to 0

    //OTHER OVERLOADING FUNCTIONS
    friend Complex operator ==(const Complex& complex1, const Complex& complex2);

    friend Complex operator +(const Complex& complex1, const Complex& complex2);

    friend Complex operator -(const Complex& complex1, const Complex& complex2);

    friend Complex operator *(const Complex& complex1, const Complex& complex2);

    //overloading insertion and extraction operators
    friend istream& operator >>(istream& in, Complex& c);
    friend ostream& operator <<(ostream& out, const Complex& c);

private:
    //two variables to hold real
    //and imaginary part of a
    //complex number
    double real;
    double imaginary;
};

//defining const for imaginary number
const Complex i(0, 1);


Complex::Complex(double r, double i) : real(r), imaginary(i) {}
Complex::Complex(double r) : real(r), imaginary(0) {}
Complex::Complex() : real(0), imaginary(0) {}

//overloading operators definitions
Complex operator ==(const Complex& complex1, const Complex& complex2) {
    return (complex1.real == complex2.real && complex1.imaginary == complex2.imaginary);
}
Complex operator +(const Complex& complex1, const Complex& complex2) {
    Complex result;
    result.real = complex1.real + complex2.real;
    result.imaginary = complex1.imaginary + complex2.imaginary;
    return result;
}
Complex operator -(const Complex& complex1, const Complex& complex2) {
    Complex result;
    result.real = complex1.real - complex2.real;
    result.imaginary = complex1.imaginary - complex2.imaginary;
    return result;
}
// (a+b*i) * (c+d*i) == (a*c - b*d) + (a*d + b*c)*i
Complex operator *(const Complex& complex1, const Complex& complex2) {
    Complex result;
    result.real = complex1.real * complex2.real - complex1.imaginary * complex2.imaginary;
    result.imaginary = complex1.real * complex2.imaginary + complex1.imaginary * complex2.real;
    return result;
}
ostream& operator <<(ostream& out, const Complex& c) {
    out << "(";
    out << c.real;
    out << ", ";
    out << c.imaginary;
    out << ")\n";
    return out;
}
istream& operator >>(istream& in, Complex& c) {
    char charact;
    in >> charact;  //ignoring '('
    in >> c.real;
    in >> charact;  //ignoring ','
    in >> c.imaginary;
    in >> charact;  //ignoring ')'
    return in;
}


int main() {
    Complex c1;
    Complex c2;
    // Input form (x,y)
    cout << "Enter complex number 1: ";
    cin >> c1;
    cout << "Enter complex number 2: ";
    cin >> c2;
    cout << c1*c2;
    cout << endl;
    return 0;
}