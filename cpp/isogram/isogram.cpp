#include "isogram.h"

#include <set>
#include <cctype>

namespace isogram {

    bool is_isogram(const std::string_view& input){
        std::set<char> containingLetters{};
        
        for(char c : input){
            //multiple whitespaces and hyphens are allowed
            if(c==' ' || c=='-')
                continue;
            
            c = toupper(c);
            if(containingLetters.find(c) != containingLetters.end())
                return false;
            containingLetters.insert(c);
        }
        return true;
    }
}  // namespace isogram
