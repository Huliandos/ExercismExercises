#include "secret_handshake.h"

namespace secret_handshake {
    std::vector<std::string> commands(int code){
        std::vector<std::string> result;

        //first bit set
        if(code & (1 << 0))
            result.push_back("wink");
        if(code & (1 << 1))
            result.push_back("double blink");
        if(code & (1 << 2))
            result.push_back("close your eyes");
        if(code & (1 << 3))
            result.push_back("jump");
        if(code & (1 << 4))
            reverseVector(result);
        
        return result;
    }

    void reverseVector(std::vector<std::string>& vector){
        for(std::size_t i=0; i<vector.size()/2; i++){
            if(vector[i] != vector[vector.size()-i]){
                std::string temp = vector[i];
                vector[i] = vector[vector.size()-1-i];
                vector[vector.size()-1-i] = temp;
            }
        }
    }
}  // namespace secret_handshake
