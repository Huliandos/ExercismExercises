#include "protein_translation.h"

#include <utility>    //pair & make_pair

namespace protein_translation {
    //Easy to write for developer
    std::unordered_map<std::string_view, std::vector<std::string_view>> proteinCodonCombinations = {
        {"Methionine", {"AUG"}},
        {"Phenylalanine", {"UUU", "UUC"}},
        {"Leucine", {"UUA", "UUG"}},
        {"Serine", {"UCU", "UCC", "UCA", "UCG"}},
        {"Tyrosine", {"UAU", "UAC"}},
        {"Cysteine", {"UGU", "UGC"}},
        {"Tryptophan", {"UGG"}},
        {"STOP", {"UAA", "UAG", "UGA"}}
    };
    //auto generated in proteins function
    std::unordered_map<std::string_view, std::string_view> codonProteinCombinations;

    std::vector<std::string> proteins(std::string_view rna){
        //generate the codon protein unordered map
        for(const std::pair<std::string_view, std::vector<std::string_view>>& proteinCodonCombination : proteinCodonCombinations ) {
            for(const std::string_view& codon : proteinCodonCombination.second){
                codonProteinCombinations.insert({codon, proteinCodonCombination.first});
            }
        }

        std::vector<std::string> translated;
        for(size_t i=0; i<rna.length(); i+=3){
            std::string_view translated_protein = codonProteinCombinations[rna.substr(i, 3)];
            if(translated_protein == "STOP")
                return translated;

            //constructs a string out of string_view
            translated.emplace_back(translated_protein);
        }
        return translated;
    }
}  // namespace protein_translation
