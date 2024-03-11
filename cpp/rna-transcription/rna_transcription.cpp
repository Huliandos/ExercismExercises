#include "rna_transcription.h"

#include <stdexcept>

namespace rna_transcription {
    char to_rna(char nucleotide){
        switch(nucleotide){
            case 'A':
                return 'U';
            case 'T':
                return 'A';
            case 'C':
                return 'G';
            case 'G':
                return 'C';
        }
        
        throw std::domain_error("Invalid nucleotide. Only 'A', 'T', 'C' and 'G' are valid inputs");
    }

    std::string to_rna(std::string dna){
        for(char& nucleotide: dna){
            nucleotide = to_rna(nucleotide);
        }
        return dna;
    }
}  // namespace rna_transcription
