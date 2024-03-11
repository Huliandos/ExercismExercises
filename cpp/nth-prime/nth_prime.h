#if !defined(NTH_PRIME_H)
#define NTH_PRIME_H

#include <vector>

namespace nth_prime {
    int nth(int);

    std::vector<int> generatePrimeVector(int);
    void clearOutNonPrimes(int, std::vector<int>&);
    int getIndexOfValue(const std::vector<int>&, int);
}  // namespace nth_prime

#endif // NTH_PRIME_H