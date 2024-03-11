#include "hamming.h"

#include <stdexcept>

namespace hamming {
    int compute(std::string a, std::string b){
        if(a.length() != b.length()) {
            throw std::domain_error("different DNA sequence lengths");
        }

        int hammingDistance = 0;
        for(long unsigned i=0; i<a.length(); i++){
            if(a[i] != b[i]) hammingDistance++;
        }
        return hammingDistance;
    }
}  // namespace hamming
