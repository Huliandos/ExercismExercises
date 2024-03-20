#include "run_length_encoding.h"

#include <cctype>

namespace run_length_encoding {
    std::string encode(const std::string_view& input){
        std::string encoded{};
        for(size_t i=0; i<input.size(); i++){
            char curChar = input[i];
            int occurences = 1;
            //count repeating occurences of char
            while(input[i+1] == curChar && i<input.size()){
                occurences++;
                i++;
            }
            //add num if occurences is bigger than one
            if(occurences > 1)
                encoded.append(std::to_string(occurences));
            //add char itself
            encoded.push_back(curChar);
        }
        return encoded;
    }

    std::string decode(const std::string_view& input){
        std::string decoded{};
        for(size_t i=0; i<input.size(); i++){
            //if letter or whitespace then add it to the decoded string
            if(!isdigit(input[i])){
                decoded.push_back(input[i]);
                continue;
            }
            std::string number{};
            //if number then find the whole number string
            while(isdigit(input[i])){
                number.push_back(input[i]);
                i++;
            }
            //add the first found letter or whitespace number times
            for(int j=0; j<std::stoi(number); j++)
                decoded.push_back(input[i]);
        }
        return decoded;
    }
}  // namespace run_length_encoding
