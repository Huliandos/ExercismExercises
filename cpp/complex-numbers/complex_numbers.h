#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers {
    class Complex{
private:
        const float EULER_CONSTANT = 2.7182818/*2845904523536*/;
        float realPart_;
        float imaginaryPart_;
public:
        Complex(float, float);
        float real() const;
        float imag() const;
        float abs() const;
        Complex conj() const;
        Complex exp() const;
        Complex operator +(Complex) const;
        Complex operator -(Complex) const;
        Complex operator *(Complex) const;
        Complex operator /(Complex) const;
    };
}  // namespace complex_numbers

#endif  // COMPLEX_NUMBERS_H
