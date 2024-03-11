#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count {
    counter::counter(std::string DNASequence){
        for(unsigned long i = 0; i<DNASequence.length(); i++){
            if(DNASequence[i] == 'A')
                nucleotide_nums['A'] += 1;
            else if(DNASequence[i] == 'C')
                nucleotide_nums['C'] += 1;
            else if(DNASequence[i] == 'G')
                nucleotide_nums['G'] += 1;
            else if(DNASequence[i] == 'T')
                nucleotide_nums['T'] += 1;
            else
                throw std::invalid_argument("String included illegal character");
        }
    }
    
    std::map <char, int> counter::nucleotide_counts() const{
        return nucleotide_nums;
    }
    
    int counter::count(char c) const{
        if(c == 'A' || c == 'C' || c == 'G' || c == 'T'){
            return nucleotide_nums.at(c);
        }
        throw std::invalid_argument("Illegal character");
    }
    
}  // namespace nucleotide_count
