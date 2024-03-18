#include "hexadecimal.h"

#include <cctype>
#include <cmath>

namespace hexadecimal {
    int convert(const std::string_view& input){
        int decimal = 0;
        
        for(size_t i=0; i<input.size(); i++){
            char c = toupper(input[i]);
            if(c>='0' && c<='9'){
                decimal += (c-'0')*pow(16, input.size()-1-i);
                continue;
            }
            if(c>='A' && c<='F'){
                decimal += (c-'A'+10)*pow(16, input.size()-1-i);
                continue;
            }
            //only reach here with invalid input
            return 0;
        }
        
        return decimal;
    }
}  // namespace hexadecimal
