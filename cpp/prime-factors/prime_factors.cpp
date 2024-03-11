#include "prime_factors.h"

namespace prime_factors {
    std::vector<int> of(int number){
        std::vector<int> result;

        int prime = 2;
        while(number != 1){
            if(number % prime == 0){
                number /= prime;
                result.push_back(prime);
            }
            else
                prime++;
        }

        return result;
    }
}  // namespace prime_factors
