#include "bob.h"

#include <regex>

namespace bob {
    std::string hey(std::string inputSentence){
        //remove all irrelevant special chars
        inputSentence = std::regex_replace(inputSentence, std::regex("[^a-zA-Z0-9?]"), "$1");
        
        //not actually saying anything
        if(inputSentence.size()==0)
            return "Fine. Be that way!";

        bool question = false;
        if(inputSentence[inputSentence.size()-1] == '?')
            question = true;
        
        //remove all numbers and question marks after checking for empty string
        inputSentence = std::regex_replace(inputSentence, std::regex("[^a-zA-Z]"), "$1");

        //question
        if(question){
            //yelling
            if(isYelling(inputSentence))
                return "Calm down, I know what I'm doing!";
            //normal question
            return "Sure.";
        }
        
        //yelling
        if(isYelling(inputSentence))
                return "Whoa, chill out!";
        
        //default response
        return "Whatever.";
    }

    bool isYelling(const std::string& inputSentence){
        //if there are no letters then you can't be screaming
        if(inputSentence.size()==0)
            return false;
        
        //check if each letter is capitelized
        for(char c: inputSentence){
            if(c > 90 || c < 65)
                return false;
        }
        return true;
    }
}  // namespace bob
