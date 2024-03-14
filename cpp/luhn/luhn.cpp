#include "luhn.h"

#include <algorithm>
#include <cctype>
#include <iostream>

namespace luhn {
    bool valid(std::string input){
        //erase remove idiom to remove all whitespaces
        auto noSpaceEnd = std::remove(input.begin(), input.end(), ' ');
        input.erase(noSpaceEnd, input.end());
    
        //Strings of length 1 or less are not valid
        if(input.size() <= 1)
            return false;

        //All other non-digit characters are disallowed
        if(!all_of(input.begin(), input.end(), ::isdigit))
            return false;

        //starting from the right, double every second digit
        for(int i=input.size()-2; i>= 0; i-=2){
            //double
            int doubled = (input[i] - '0') * 2;
            if(doubled > 9)
                doubled -= 9;
            input[i] = doubled + '0';
        }

        //sum up all numbers
        int sum {0};
        for(char c : input)
            sum += c - '0';

        //if divisible by then then the  number is valid
        return sum%10 == 0;
    }
}  // namespace luhn
