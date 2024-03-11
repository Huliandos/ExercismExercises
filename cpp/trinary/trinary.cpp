#include "trinary.h"

#include <math.h>

namespace trinary {
    int to_decimal(std::string trinary){
        int decimalNumber = 0;
        for(size_t i=0; i<trinary.size(); i++){
            //input validation
            if(trinary[i]>='0' && trinary[i]<='2'){
                //converts it to number by substracting ASCII values
                int numberAtI = trinary[i] - '0';
                //-1 cause we start indexing at 0
                numberAtI*=pow(3, trinary.size()-1-i);
                decimalNumber+=numberAtI;
            }
        }
        return decimalNumber;
    }
}  // namespace trinary
