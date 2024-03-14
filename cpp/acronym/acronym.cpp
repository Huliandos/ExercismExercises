#include "acronym.h"

#include <algorithm>

namespace acronym {

    std::string acronym(const std::string& input){
        std::string acro{input[0]};

        for(size_t i=1; i<input.size(); i++){
            //if char is not a letter and not and apostrophe (') and next char is a letter
            if(!std::isalpha(input[i]) && input[i] != '\'' && std::isalpha(input[i+1])){
                //add letter to acronym
                acro.push_back(input[i+1]);
            }
        }
        
        std::transform(acro.begin(), acro.end(), acro.begin(), ::toupper);
        
        return acro;
    }
}  // namespace acronym
