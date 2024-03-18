#include "binary.h"

#include <cmath>

namespace binary {
    int convert(std::string_view input){
        int decimal = 0;
        
        for(size_t i=0; i<input.size(); i++){
            if(!(input[i] == '0' || input[i] == '1'))
                return 0;
            decimal += (input[i]-'0')*pow(2, input.size()-1-i);
        }
        
        return decimal;
    }
}  // namespace binary
