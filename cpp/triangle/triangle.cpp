#include "triangle.h"
#include "stdexcept"

namespace triangle {
    flavor kind(double a, double b, double c){
        //False input handling
        if(a==0 || b==0 || c==0){
            throw std::domain_error("Triangle side length can't be 0");
        }
        if(a<0 || b<0 || c<0){
            throw std::domain_error("Triangle side length can't be smaller than 0");
        }
        if(a+b<c || a+c<b || b+c<a){
            throw std::domain_error("Triangle must respect triangle inequality (he sum of the lengths of any two sides must be greater than or equal to the length of the third side)");
        }

        //calculate triangle type
        if(a == b && a == c){
            //equilateral
            return flavor::equilateral;
        }
        if(a==b || a==c || b==c){
            //isosceles
            return flavor::isosceles;
        }
        //scalene
        return flavor::scalene;
    }

}  // namespace triangle
