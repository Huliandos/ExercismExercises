#include "sum_of_multiples.h"

namespace sum_of_multiples {
    int to(std::vector<int> numbers, int upperBorder){
        int total = 0;
        //-1 'cause we're not including the upper border
        upperBorder -= 1;

        //just works for up to 3 numbers currently
        for(size_t i=0; i<numbers.size(); i++){
            total += sumOfMultiples(numbers[i], upperBorder);

            //substract all common divisors
            for(size_t j=0; j<i; j++){
                total -= sumOfMultiples(lcm(numbers[i],numbers[j]), upperBorder);

                //add back all divisors common by three numbers
                for(size_t k=0; k<j; k++){
                    total += sumOfMultiples(lcm(numbers[i],lcm(numbers[j], numbers[k])), upperBorder);
                }
            }
        }
        
        return total;
    }

    int sumOfMultiples(int number, int upperBorder){
        int numberOfMultiples = upperBorder/number;
        //formula:  sum = a * (Summation of 1 to m [natural numbers from 1 to m]) 
        //Summation of 1 to m: m * (m + 1) / 2
        //a = numbers[i], m=number of multiples
        return number * (numberOfMultiples * (numberOfMultiples+1) / 2);
    }

    //least common multiple
    int lcm(int a, int b){
        //least common multiple = product of numbers / greatest common divisor
        return a*b/gcd(a, b);
    }

    //greatest common divisor recursively
    int gcd(int a, int b)
    {
        // Everything divides 0
        if (a == 0)
           return b;
        if (b == 0)
           return a;
      
        // base case
        if (a == b)
            return a;
      
        // a is greater
        if (a > b)
            return gcd(a-b, b);
        return gcd(a, b-a);
    }
}  // namespace sum_of_multiples
