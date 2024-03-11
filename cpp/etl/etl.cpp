#include "etl.h"

#include <utility>

namespace etl {
    std::map<char, int> transform(const std::map<int, std::vector<char>>& oldDataset){
        std::map<char, int> transformedData;

        for(const std::pair<int, std::vector<char>> &myPair : oldDataset ) {
            for(const char c : myPair.second){
                transformedData.insert({toLower(c), myPair.first});
            }
        }   
        
        return transformedData;
    }

    //casts a char to lower case
    char toLower(char c){
        //c is between A and Z
        if(c>= 65 && c <= 90 )
            //cast to lowercase
            return c + 32;
        return c;
    }
}  // namespace etl
