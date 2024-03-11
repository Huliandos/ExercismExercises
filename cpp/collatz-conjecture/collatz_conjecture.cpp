#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture {
    //Iterative solution
    int steps(int num){
        if(num <= 0) throw std::domain_error("Input can't be negative nor 0");

        int counter = 0;

        while(num!=1){
            counter++;
            //num is even. num&1 == num%2
            if((num&1)==0)
                num /= 2;
            else 
                num = 3*num+1;
        }

        return counter;
    }
}  // namespace collatz_conjecture
