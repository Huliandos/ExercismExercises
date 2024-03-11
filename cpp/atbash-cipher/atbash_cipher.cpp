#include "atbash_cipher.h"

#include <regex>

namespace atbash_cipher {
    std::string encode(std::string message){
        std::string encodedMessage = "";

        int i=0;
        for(char c: message){
            c = translateCharacter(c);

            if(c!='\0'){
                encodedMessage+=c;
                i++;
                //add blank space every 5 letters
                if(i%5==0)
                   encodedMessage+= " "; 
            }
        }

        //remove leading and trailing whitespaces
        encodedMessage = std::regex_replace(encodedMessage, std::regex("^ +| +$"), "$1");
        
        return encodedMessage;
    }
    
    std::string decode(std::string message){
        std::string decodedMessage = "";

        for(char c: message){
            c = translateCharacter(c);

            if(c!='\0')
                decodedMessage+=c;
        }
        
        return decodedMessage;
    }

    char translateCharacter(char c){
        if(((int)c) <= 46)
            return '\0';

        //letters
        if(((int)c) >= 65){
            //uppercase letter
            if(((int)c) <= 90){
                //cast to lowercase
                c = (char)((int)c + 32);
            }

            //translate
            c = (char)(97+(122-((int)c)));
        }

        //return numbers unchanged (48-57)
        return c;
    }

}  // namespace atbash_cipher
