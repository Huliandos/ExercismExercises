#include "reverse_string.h"

namespace reverse_string {
    std::string reverse_string(std::string str){
        int index = 0;
        char buffer;
        while(index < (int)(str.length()/2)){
            buffer = str[index];
            str[index] = str[str.length()-1-index];
            str[str.length()-1-index] = buffer;
            index++;
        }
        return str;
    }
}  // namespace reverse_string
