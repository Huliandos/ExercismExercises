#include "rotational_cipher.h"

#include <cctype>

namespace rotational_cipher {
    std::string rotate(const std::string_view& input, int shift){
        std::string encoded{};
        for(char c : input){
            //letter
            if(isalpha(c)){
                char base = std::islower(c) ? 'a' : 'A';
                encoded.push_back((c-base+shift)%26+base);
                continue;
            }
            //other char
            encoded.push_back(c);
        }
        return encoded;
    }
}  // namespace rotational_cipher
