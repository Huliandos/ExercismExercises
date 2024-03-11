#include "say.h"

#include <stdexcept>
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>    //string trimming

namespace say {
    //all individual special cases
    std::map<int, std::string> numbersToText 
        {{0, ""}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, 
        {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, //1 digit nums
        {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {15, "fifteen"},     //special teens
        {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"}, 
        {60, "sixty"}, {70, "seventy"}, {80, "eighty"}, {90, "ninety"}};    //tys

    std::vector<std::string> bigNumAdditions {"hundred", "thousand", "million", "billion"};


    std::string in_english(unsigned long long number){
        if(number >= 1'000'000'000'000ULL) throw std::domain_error("Input overflowed into negative or positive direction");
        if(number == 0ULL) return "zero";

        //convert number into array
        std::string numberAsString = std::to_string(number);

        std::string result = generateStringResult(numberAsString);

        return result;
    }

    //logic for splitting input in triplets
    std::string generateStringResult(const std::string& totalNumString){
        std::string result = "";
        
        //0 = 0-99, 1 = 100-99'999, 2 = 1'000'000-999'999'999 etc.
        int numberAdditionIndex = (totalNumString.length()-1)/3;

        int digitNumExceedingTriplet = totalNumString.length()%3;
        
        if(digitNumExceedingTriplet != 0){
            result += generateStringForTuplet(totalNumString.substr(0,digitNumExceedingTriplet));
            
            //we are in the thousands or above
            if(numberAdditionIndex > 0){
                result += " " + bigNumAdditions[numberAdditionIndex] + " ";
                numberAdditionIndex-=1;
            }
            //we are bellow the hundrets -> Skip the loop
            else{
                goto SkipLoop;
            }
        }

        //we are in the thousands or above
        for(std::size_t i=digitNumExceedingTriplet; i<totalNumString.length(); i+=3){
            //adding the hundrets of the number triplet
            if(totalNumString[i]!='0'){
                std::cout << "entered " << totalNumString[i] << std::endl;
                result+=numbersToText[charToInt(totalNumString[i])] + " " + bigNumAdditions[0] + " ";
                }

            //adding the tuplet string
            result += generateStringForTuplet(totalNumString.substr(i+1,2));

            //adding size of our number (thousand, million, billion etc.)
            //but only if no numbers of the triplet are equal to 0
            if(numberAdditionIndex>0 && (totalNumString[i]!='0' || totalNumString[i+1]!='0' || totalNumString[i+2]!='0')){
                result += " " + bigNumAdditions[numberAdditionIndex] + " ";
            }
            numberAdditionIndex-=1;
        }
        
        //cut off white spaces at the end
        boost::algorithm::trim_right(result);
        
SkipLoop:
        return result;
    }

    //logic for generating tuplets from 0-99
    std::string generateStringForTuplet(const std::string& tuplet){
        std::string result = "";

        //in case we skip the teens
        int indexModifier = 0;
        
        //just a single digit input
        if(1 == tuplet.length()){
            indexModifier = 1;
            goto SingleDigit;
        }

        //input is along the lines of 01, 06, 03 etc.
        if(tuplet[0] == '0')
            goto SingleDigit;

        //Special case: teens
        if(tuplet[0] == '1'){
            //special case: 10, 11, 12, 13, 15
            if(tuplet[1]==0 || tuplet[1]==1 || tuplet[1]==2 || tuplet[1]==3 || tuplet[1]==5)
            {
                result+=numbersToText[charToInt(tuplet[0])*10 + charToInt(tuplet[1])];
            }
            else 
            {
                result+=numbersToText[charToInt(tuplet[1])] + "teen";
            }
            goto SkipSingles;
        }
        else{
            result+=numbersToText[charToInt(tuplet[0])*10]+"-";
        }
        
SingleDigit:
        result+=numbersToText[charToInt(tuplet[1-indexModifier])];
        
SkipSingles:
        boost::algorithm::trim_right_if(result, &isMinus);
        boost::algorithm::trim_right(result);

        return result;
    }

    int charToInt(char c){
        //ASCII num representation - 48 (0) --> gives us the numbers as int 0-9
        return c - '0';
    }

    bool isMinus(char c){
        return c=='-';
    }

    void segmentationViolationHandler(int signal){
        throw std::domain_error("Input overflowed into negative or positive direction with signal num: " + signal);
    }
}  // namespace say
