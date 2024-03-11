#include "grains.h"

namespace grains {
    unsigned long long int square(int squareNum){
        //performance
        return 1ULL<<(squareNum-1);
        //readable
        //return pow(2, squareNum-1);
    }

    unsigned long long int total(){
        //performance
        //total grains up to square n = grains(n)*2-1
        return square(chessBoardSquares)*2-1;
        //readable
        /*
        unsigned long long int totalNum = 0;
        for(int i = 1; i<=chessBoardSquares; i++){
            totalNum += square(i);
        }
        return totalNum;
        */
    }
}  // namespace grains
