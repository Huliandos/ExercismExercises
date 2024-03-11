#include "complex_numbers.h"

#include <math.h>

namespace complex_numbers {
        Complex::Complex(float realPart, float imaginaryPart){
            realPart_ = realPart;
            imaginaryPart_ = imaginaryPart;
        }

        float Complex::real() const{
            return realPart_;
        }

        float Complex::imag() const{
            return imaginaryPart_;
        }

        float Complex::abs() const{
            //|z| = sqrt(a^2 + b^2)
            return sqrt(pow(realPart_, 2) + pow(imaginaryPart_, 2));
        }

        Complex Complex::conj() const{
            //a - b * i
            return Complex(realPart_, -imaginaryPart_);
        }

        Complex Complex::exp() const{
            //e^(a + i * b) = e^a * e^(i * b)
            //e^(i * b) = cos(b) + i * sin(b)
            float ePowR = pow(EULER_CONSTANT, realPart_);
            return Complex(ePowR * cos(imaginaryPart_),  ePowR * sin(imaginaryPart_));
        }

        Complex Complex::operator +(Complex otherComplexNum) const{
            //(a + i * b) + (c + i * d) = (a + c) + (b + d) * i
            return Complex(realPart_ + otherComplexNum.real(), imaginaryPart_ + otherComplexNum.imag());
        }

        Complex Complex::operator -(Complex otherComplexNum) const{
            //(a + i * b) - (c + i * d) = (a - c) + (b - d) * i
            return Complex(realPart_ - otherComplexNum.real(), imaginaryPart_ - otherComplexNum.imag());
        }

        Complex Complex::operator *(Complex otherComplexNum) const{
            //(a + i * b) * (c + i * d) = (a * c - b * d) + (b * c + a * d) * i
            return Complex(realPart_ * otherComplexNum.real() - imaginaryPart_ * otherComplexNum.imag(), 
                imaginaryPart_ * otherComplexNum.real() + realPart_ * otherComplexNum.imag());
        }

        Complex Complex::operator /(Complex otherComplexNum) const{
            //(a + i * b) / (c + i * d) = (a * c + b * d)/(c^2 + d^2) + (b * c - a * d)/(c^2 + d^2) * i
            float divider = pow(otherComplexNum.real(), 2) + pow(otherComplexNum.imag(), 2);
            return Complex((realPart_ * otherComplexNum.real() + imaginaryPart_ * otherComplexNum.imag())/divider,
                (imaginaryPart_ * otherComplexNum.real() - realPart_ * otherComplexNum.imag())/divider);
        }

}  // namespace complex_numbers
