#include "armstrong_numbers.h"

#include <cmath>
#include <string>

namespace armstrong_numbers {
    bool is_armstrong_number(int input){
        int armstrong = 0;
        std::string inputAsString = std::to_string(input);
        for(char c : inputAsString){
            armstrong += pow((c-'0'), inputAsString.size());
        }
        return armstrong == input;
    }
}  // namespace armstrong_numbers
