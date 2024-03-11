#include "word_count.h"

#include <regex>

namespace word_count {
    std::map<std::string, int> words(std::string inputSentence){
        std::map<std::string, int> wordOccurences;

        //replace all unused chars with whitespaces
        inputSentence = std::regex_replace(inputSentence, std::regex("[^a-zA-Z0-9']"), " ");
        
        //add whitespace to the end as final separator
        inputSentence += ' ';
        
        //remove all repeating whitespace occurances (resulting from replacing them earlier)
        inputSentence = std::regex_replace(inputSentence, std::regex("  +"), " ");

        //remove all leading whitespaces
        inputSentence = std::regex_replace(inputSentence, std::regex("^ +"), "$1");
        
        //convert word to all lowercase, so that we can remove case sensitivity
        convertToLower(inputSentence);
        
        size_t pos = 0;
        //iterate string split by whitespaces
        while ((pos = inputSentence.find(" ")) != std::string::npos) {
            std::string word = inputSentence.substr(0, pos);

            //remove leading and trailing semicolons
            word = std::regex_replace(word, std::regex("^'+|'+$"), "$1");
            
            std::map<std::string, int>::iterator mapIterator = wordOccurences.find(word);
            //map contains word
            if(mapIterator != wordOccurences.end())
                mapIterator->second+=1;
            else
                wordOccurences.insert({word, 1});
            
            //erase word from input + whitespace character
            inputSentence.erase(0, pos + 1);
        }

        return wordOccurences;
    }

    void convertToLower(std::string& stringToConvert){
        for(char& c: stringToConvert) {
            c = std::tolower(c);
        }
    }
}  // namespace word_count
