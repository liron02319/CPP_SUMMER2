/**
 * Liron Cohen -312324247 - liron02319@gmail.com
 */


#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>

/*
    Complex class that represents a complex number.
    To be used in the tree class.
    
    Example : 2+5i
*/
class Complex{

    private:
        double re; // re part of the complex number
        double im;  // Imaginary part of the complex number



    public:

        // Constructor that initializes a complex number with re and imaginary parts
        Complex(double r, double i) : re(r), im(i) {}

        // Getters
        double get_re() const { return re; }
        double get_imag() const { return im; }

        // Method to calculate the  absolute value of the complex number
        double absolute_value() const { return sqrt(re * re + im * im); }
        

        // Operator overload for addition of two complex numbers
        Complex operator+(const Complex &c) const {
            return Complex(re + c.re, im + c.im);
        }

        // Operator overload for subtraction of two complex numbers
        Complex operator-(const Complex &c) const {
            return Complex(re - c.re, im - c.im);
        }

    // Operator overload for multiplication of two complex numbers

        Complex operator*(const Complex &c) const {
            return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
        }

    // Operator overload for division of two complex numbers

        Complex operator/(const Complex &c) const {
            double denominator = c.re * c.re + c.im * c.im;
            return Complex((re * c.re + im * c.im) / denominator, (im * c.re - re * c.im) / denominator);
        }
        
       
        // Operator overload for equality check

        bool operator==(const Complex &c) const {
            return re == c.re && im == c.im;
        }

        // Operator overload for inequality check

        bool operator!=(const Complex &c) const {
            return !(*this == c);
        }
        
        // Operator overload for negation of the complex number

        Complex operator-() const {
            return Complex(-re, -im);
        }


            // Operator overload for compound addition

        Complex operator+=(const Complex &c) {
            re += c.re;
            im += c.im;
            return *this;
        }

            // Operator overload for compound subtraction

        Complex operator-=(const Complex &c) {
            re -= c.re;
            im -= c.im;
            return *this;
        }

            // Operator overload for compound multiplication

        Complex operator*=(const Complex &c) {
            double temp = re;
            re = re * c.re - im * c.im;
            im = temp * c.im + im * c.re;
            return *this;
        }

            // Operator overload for compound division

        Complex operator/=(const Complex &c) {
            double denominator = c.re * c.re + c.im * c.im;
            double temp = re;
            re = (re * c.re + im * c.im) / denominator;
            im = (im * c.re - temp * c.im) / denominator;
            return *this;
        }


    // Operator overload for less than comparison based on magnitude

        bool operator<(const Complex &c) const {
            return absolute_value() < c.absolute_value();
        }
        
    // Operator overload for less than or equal to comparison based on magnitude
        bool operator<=(const Complex &c) const {
            return absolute_value() <= c.absolute_value();
        }

    // Operator overload for greater than comparison based on magnitude
        bool operator>(const Complex &c) const {
            return absolute_value() > c.absolute_value();
        }


     // Operator overload for greater than or equal to comparison based on magnitude
        bool operator>=(const Complex &c) const {
            return absolute_value() >= c.absolute_value();
        }

      // Friend function declarations for stream insertion and extraction
        friend std::ostream &operator<<(std::ostream &os, const Complex &c) ;
        friend std::istream &operator>>(std::istream &is, Complex &c);


};





   std::ostream &operator<<(std::ostream &os, const Complex &c) {
            os << c.re << "+" << c.im << "i";
            return os;
        }

          std::istream &operator>>(std::istream &is, Complex &c) {
            is >> c.re >> c.im;
            return is;
        }
#endif
