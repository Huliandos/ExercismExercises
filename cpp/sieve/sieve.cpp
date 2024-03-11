#include "sieve.h"

#include <map>

namespace sieve {
    std::vector<int> primes(int range){
        std::vector<int> primes;
        if(range < 2) return primes;

        std::map<int, bool> flaggedPrimes;
        for(int i=2; i<=range; i++){
            flaggedPrimes.insert({i, true});
        }
        
        int currentPrime = 2;
        while(currentPrime*2 <= range){
            //start at multiple of current prime
            for(int i = currentPrime*2; i<=range; i+= currentPrime){
                flaggedPrimes[i] = false;
            }
            currentPrime++;
        }

        //assign all primes to vector
        for(int i=2; i<=range; i++){
            if(flaggedPrimes[i] == true)
                primes.push_back(i);
        }

        //return vector
        return primes;
    }
}  // namespace sieve
