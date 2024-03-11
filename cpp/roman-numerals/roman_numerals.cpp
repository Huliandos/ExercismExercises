#include "roman_numerals.h"

namespace roman_numerals {
    std::string thousands[] = {"", "M", "MM", "MMM"};  
    std::string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};  
    std::string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};  
    std::string units[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};  

    std::string convert(int number){
        return thousands[number/1000] + hundreds[number%1000/100] + tens[number%100/10] + units[number%10];
    }  // namespace roman_numerals
}