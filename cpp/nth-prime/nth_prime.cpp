#include "nth_prime.h"

#include <stdexcept>
#include <math.h>       // pow

//Sieve of Eratosthenes algo
namespace nth_prime {
    int nth(int nthPrime){
        if(nthPrime < 1) throw std::domain_error("Invalid Input");

        std::vector<int> primes = generatePrimeVector(nthPrime);

        //-1, because position 1 = array/list position 0
        return primes[nthPrime-1];
    }

    std::vector<int> generatePrimeVector(int nthPrime){
        //initial variables
        bool exitLoop = false;
        int size = 2, generationStartValue = 2;

        //reserve initial size for vector
        std::vector<int> primes;

        while(!exitLoop){
            //This has to be at least bigger than n
            int numberToGenerateTo = size*nthPrime;
    
            //generate list or add  to existing including all numbers from generationStartValue to numberToGenerateTo
            for(int i=generationStartValue; i<=numberToGenerateTo; i++){
                primes.push_back(i);
            }

            clearOutNonPrimes(numberToGenerateTo, primes);
            
            //if vector size is large enough to include the nth prime, we can exit the loop
            if(primes.size() >= static_cast<unsigned long>(nthPrime)){
                exitLoop = true;
            }
            //if we didn't generate a big enough initial list size
            else{
                size++;
                generationStartValue = primes[primes.size()]+1;
            }
        }
        
        return primes;
    }

    void clearOutNonPrimes(int numberToGenerateTo, std::vector<int>& primes){
        int currentPrimePos = 0;
            //removing all non primes
            //we can stop iteration once p^2 is greater than biggest element of list (size of list)
            while(pow(currentPrimePos, 2) <= numberToGenerateTo){
                //all factors of p less than p^2 are crossed out by previous smaller primes
                //--> start iteration from p^2
                for (std::vector<int>::iterator it = primes.begin()+getIndexOfValue(primes, pow(primes[currentPrimePos], 2));
                    it != primes.end();) {
                    //remove if not a prime
                    if (*it != primes[currentPrimePos] && *it % primes[currentPrimePos] == 0) {
                        it = primes.erase(it);
                    } else {
                        it++;
                    }
                }
                currentPrimePos++;
            }
    }

    //Get index at value or higher
    int getIndexOfValue(const std::vector<int>& vector, int value){
        for(unsigned long i=0; i < vector.size(); i++){
            if(vector[i] < value)
                return static_cast<int>(i);
        }
        return vector.size()-1;
    }
}  // namespace nth_prime