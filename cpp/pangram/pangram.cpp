#include "pangram.h"
#include <algorithm>

namespace pangram {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    bool is_pangram(std::string input){
        //input string isn't long enough to even have all letters of the alphabet in it
        if(alphabet.length() > input.length()) return false;

        //convert input to all lowercase
        std::for_each(input.begin(), input.end(), [](char &c){
            c = tolower(c);
        });
        
        for(long unsigned i=0; i<alphabet.length(); i++){
            //letter not found
            if(input.find(alphabet[i]) == std::string::npos) return false;
        }
        return true;
    }
}  // namespace pangram
