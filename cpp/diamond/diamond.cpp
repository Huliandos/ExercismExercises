#include "diamond.h"

namespace diamond {
    std::vector<std::string> rows(char maxLetter){
        std::vector<std::string> diamond{};

        std::string row{};
            
        //Add first A
        addMultipleOfChar(row, ' ', (maxLetter-'A'));
        row.push_back('A');
        addMultipleOfChar(row, ' ', (maxLetter-'A'));
        diamond.push_back(row);
        
        row = "";
        
        //Generate diamond up to the max letter
        for(int i=1; i<=(maxLetter-'A'); i++){
            //add preceding whitespaces
            addMultipleOfChar(row, ' ', (maxLetter-'A')-i);
            
            //add letter
            row.push_back(static_cast<char>('A'+i));

            //add in between whitespaces
            addMultipleOfChar(row, ' ', i*2-1);

            //add letter
            row.push_back(static_cast<char>('A'+i));

            //add following whitespaces
            addMultipleOfChar(row, ' ', (maxLetter-'A')-i);

            diamond.push_back(row);

            row = "";
        }

        //copy rows from middle to top to finish the diamond
        for(int i=0; i<(maxLetter-'A'); i++){
            diamond.push_back(diamond[(maxLetter-'A')-i-1]);
        }
        
        return diamond;
    }

    void addMultipleOfChar(std::string& str, char charToAdd, int numToAdd){
        int i=0;
        while(i<numToAdd){
            str.push_back(charToAdd);
            i++;
        }
    }
}  // namespace diamond
