#include "raindrops.h"

namespace raindrops {
    std::string convert(int numToConvert){
        std::string result = "";
        if(numToConvert%3 == 0) result += "Pling";
        if(numToConvert%5 == 0) result += "Plang";
        if(numToConvert%7 == 0) result += "Plong";

        if(result == "") return std::to_string(numToConvert);
        else return result;
    }
}  // namespace raindrops
