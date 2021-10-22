#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#include "Complex.h"

//Constructors. There are three constructors, a default, and then two that allow the user to enter in values.

Complex::Complex (){
  realComp = 0;
  iComp = 0;
}

Complex::Complex (double a) {
  realComp = a;
  iComp = 0;
}

Complex::Complex(double a, double b){
  realComp = a;
  iComp = b;
}

//Setters. These set the values for imaginary and real part of the complex number.

void Complex::setValue(double real = 0, double i = 0) {
  realComp = real;
  iComp = i;
}

void Complex::setReal(double real) {
  realComp = real;
}

void Complex::setImaginary(double i){
  iComp = i;
}

//Functions. These are functions that are used to perform operations.

void Complex::add(Complex complex1){ //This is mutating an object with another object. The formula for this is that off addition for complex numbers.

  double addRealVal;
  double addIVal;

  addRealVal = realComp + complex1.getRealPart(); //mutates
  addIVal = iComp + complex1.getImaginaryPart();

  realComp = addRealVal;
  iComp = addIVal;

}

void Complex::subtract(Complex complex1){ //This is mutating an object with another object. The formula for this is that off subtraction for complex numbers.
  double subRealVal;
  double subIVal;

  subRealVal = realComp - complex1.getRealPart();
  subIVal = iComp - complex1.getImaginaryPart();


  realComp = subRealVal;
  iComp = subIVal;

}

void Complex::multiply(Complex complex1){ //This is mutating an object with another object. The formula for this is that off multiplication for complex numbers.
  double multipliedRealVal;
  double multipliedIVal;

  multipliedRealVal = realComp * complex1.getRealPart() - iComp * complex1.getImaginaryPart();
  multipliedIVal = iComp * complex1.getRealPart() + realComp * complex1.getImaginaryPart();

  realComp = multipliedRealVal;
  iComp = multipliedIVal;

}

void Complex::divide(Complex complex1){ //This is mutating an object with another object. The formula for this is that off division for complex numbers.
  double dividedRealVal;
  double dividedIVal;

  dividedRealVal = (realComp * complex1.getRealPart() + iComp * complex1.getImaginaryPart())/(pow(complex1.getRealPart(),2) + pow(complex1.getImaginaryPart(), 2));

  dividedIVal = (iComp * complex1.getRealPart() - realComp * complex1.getImaginaryPart()) / (pow(complex1.getRealPart(),2) + pow(complex1.getImaginaryPart(), 2));

  realComp = dividedRealVal;
  iComp = dividedIVal;

}

double Complex::abs(){ //This is mutating an object with another object. The formula for this is that off determining the absolute value for complex numbers.
  double abs;
  abs  = sqrt(pow(realComp,2) + pow(iComp,2));
  return abs;
}

string Complex::toString() { //This code is used to output the results of the computations
  string a = to_string(realComp);
  string b = to_string(iComp);
  string complexString = "";

  if (iComp > 0) {
    return (a + " + " + b + "i");
  }
  else if (iComp < 0) {
    return (a  + b + "i");
  }
  else {

    return a;
  }
}


//Member overloading

Complex Complex::operator+=(double num){
  //mutates and returns calling Complex obj
  realComp = realComp + num;
  return *this;

}


Complex Complex::operator+=(Complex num){
  //mutates and returns calling Complex obj
  this->add(num);
  return *this;

}


Complex Complex::operator-=(double num){
  //mutates and returns calling Complex obj
  realComp = realComp - num;
  return *this;
}

Complex Complex::operator-=(Complex num){
  this->subtract(num);
  return *this;
}

Complex Complex::operator*=(double num){
  //mutates and returns calling Complex obj
  realComp = realComp * num;
  iComp = iComp * num;
  return *this;
}

Complex Complex::operator*=(Complex num){
  //mutates and returns calling Complex obj
  this->multiply(num);
  return *this;
}

Complex Complex::operator/=(double num){
  //mutates and returns calling Complex obj
  realComp = realComp / num;
  return *this;
}

Complex Complex::operator/=(Complex num){
  //mutates and returns calling Complex obj
  this->divide(num);
  return *this;
}

Complex& Complex::operator++(){
  //prefix
  realComp++;
  return *this;
}
Complex Complex::operator++(int){
  //postfix
  Complex temp = *this;
  ++realComp;
  return temp;

}
double& Complex::operator[](int x){
  //0 acesses real comonent, 1 acesses imaginary component
  if (x == 0){
    return realComp;
  }
  else if(x == 1){
    return iComp;
  }

}

//Non-member overloading

Complex operator+(Complex complex1, Complex complex2){
  // calls addition to modify real and imaginary component
  Complex result = complex1;
  result.add(complex2);
  return result;
}

Complex operator+(Complex complex1, double num) {
  // This is used to add to the real component of an object
  complex1.setReal(complex1.getRealPart() + num);
  return complex1;
}

Complex operator+(double num, Complex complex1) {
  //only cares about the real component
  complex1.setReal(num + complex1.getRealPart());
  return complex1;
}


Complex operator-(Complex complex1, Complex complex2){
  //calls subtract to modify real and imaginary component
  Complex result = complex1;
  result.subtract(complex2);
  return result;
}

Complex operator-(Complex complex1, double num){
  //only cares about the real component
  complex1.setReal(complex1.getRealPart() + num);
  return complex1;
}

Complex operator-(double num, Complex complex1){
  //only cares about the real component
  complex1.setReal(num + complex1.getRealPart());
  return complex1;
}

Complex operator*(Complex complex1, Complex complex2){
  //calls multiply to get correct real and imaginary component
  Complex result = complex1;
  result.multiply(complex2);
  return result;

}

Complex operator*(Complex complex1, double num){
  //scales real and imaginary component
  complex1.setReal(complex1.getRealPart() * num);
  complex1.setImaginary(complex1.getImaginaryPart() * num);
  return complex1;
}

Complex operator*(double num, Complex complex1){
  //scales real and imaginary component
  complex1.setReal(num * complex1.getRealPart());
  complex1.setImaginary(num * complex1.getImaginaryPart());
  return complex1;
}

Complex operator/(Complex complex1, Complex complex2){
  //calls divide to get correct real and imaginary component
  Complex result = complex1;
  result.divide(complex2);
  return result;

}
Complex operator/(Complex complex1, double num){
  //scales real and imaginary component
  complex1.setReal(complex1.getRealPart() / num);
  complex1.setImaginary(complex1.getImaginaryPart() / num);
  return complex1;
}

Complex operator/(double num, Complex complex1){
  //scales real and imaginary component
  complex1.setReal(num / complex1.getRealPart());
  complex1.setImaginary(num / complex1.getImaginaryPart());
  return complex1;
}

ostream& operator<<(ostream& out, Complex c1) {
// Outputs the final values using the toString function
  string str = c1.toString();
  out << str;

  return out;
}

istream& operator>>(istream& in, Complex& c1) {
  // The user enters the values through this overloading. The first entry is assigned to the real part and the second entry is assigned to the imaginary part.
  cout << "Enter the real component followed by the imaginary component seperated by a space" << endl;
  double a;
  double b;
  in >> a >> b;
  c1.setReal(a);
  c1.setImaginary(b);

  return in;
}
