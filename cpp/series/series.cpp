#include "series.h"

#include <stdexcept>

namespace series {

    std::vector<int> digits(std::string_view inputNumbers){
        std::vector<int> extractedDigits;

        for(char c: inputNumbers){
            //no error handling with unexpected characters in this task
            extractedDigits.push_back(c-'0');
        }

        return extractedDigits;
    }

    std::vector<std::vector<int>> slice(std::string_view inputNumbers, size_t sliceSize){
        if(sliceSize > inputNumbers.size())
            throw std::domain_error("Can't have slices larger than total string size");
        
        std::vector<std::vector<int>> slicedDigits;

        for(size_t i=0; i<inputNumbers.size()-(sliceSize-1); i++){
            slicedDigits.push_back(digits(inputNumbers.substr(i, sliceSize)));
        }

        return slicedDigits;
    }

}  // namespace series
