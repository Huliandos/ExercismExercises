#include "isbn_verifier.h"

#include <algorithm>
#include <cctype>

namespace isbn_verifier {
    bool is_valid(std::string isbn){
        //remove all hyphens
        isbn.erase(std::remove(isbn.begin(), isbn.end(), '-'), isbn.end());
        
        if(isbn.size() != 10)
            return false;

        int checkNum{0};
        for(size_t i=0; i<isbn.size()-1; i++){
            if(std::isalpha(isbn[i]))
                return false;
            
            checkNum += (isbn[i]-'0')*(10-i);
        }

        //last num handling
        //X is 10
        if(isbn[isbn.size()-1] == 'X')
            checkNum += 10;
        //other letter are invalid
        else if(std::isalpha(isbn[isbn.size()-1]))
            return false;
        //nums are added normally
        else
            checkNum += isbn[isbn.size()-1]-'0';

        return checkNum%11 == 0;
    }
}  // namespace isbn_verifier