#ifndef COMPLEX_H
#define COMPLEX_H

#include<string>

class Complex {
  private:
    double realComp;
    double iComp;

  public:
    //constructors:
    Complex();
    Complex(double a); //real only
    Complex(double a, double b); //complex + real

    //function members:
    void add(Complex complex1);
    void subtract(Complex complex1);
    void multiply(Complex complex1);
    void divide(Complex complex1);
    double abs();
    string toString();
    double getRealPart() const { return realComp; }
    double getImaginaryPart() const { return iComp; }
    void setValue(double real, double i);
    void setReal(double real);
    void setImaginary(double i);

    //Member overloading
    Complex operator+=(double);
    Complex operator-=(double);
    Complex operator*=(double);
    Complex operator/=(double);
    Complex operator+=(Complex);
    Complex operator-=(Complex);
    Complex operator*=(Complex);
    Complex operator/=(Complex);
    Complex& operator++();
    Complex operator++(int);
    double& operator[](int x);

};

  //Non-member operator overloading
  Complex operator+(Complex complex1, Complex complex2);
  Complex operator+(Complex complex1, double num);
  Complex operator+(double num, Complex complex1);
  Complex operator-(Complex complex1, Complex complex2);
  Complex operator-(Complex complex1, double num);
  Complex operator-(double num, Complex complex1);
  Complex operator*(Complex complex1, Complex complex2);
  Complex operator*(Complex complex1, double num);
  Complex operator*(double num, Complex complex1);
  Complex operator/(Complex complex1, Complex complex2);
  Complex operator/(Complex complex1, double num);
  Complex operator/(double num, Complex complex1);
  ostream& operator<<(ostream&, Complex c1);
  istream& operator>>(istream&, Complex& c1);


#endif
