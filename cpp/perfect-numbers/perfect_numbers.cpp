#include "perfect_numbers.h"

#include <stdexcept>

namespace perfect_numbers {
    classification classify(const int input){
        if(input <= 0)
            throw std::domain_error("Invalid input. Only positive integers over 0 are allowed");
        
        int sumOfFactors=0;
        
        for(int i=1; i<=input/2; i++){
            if(input%i == 0)
                sumOfFactors += i;
        }
        
        if(sumOfFactors == input)
            return classification::perfect;
        
        if(sumOfFactors < input)
            return classification::deficient;
        
        return classification::abundant;
    }
}  // namespace perfect_numbers
