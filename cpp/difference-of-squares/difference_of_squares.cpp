#include "difference_of_squares.h"

#include <stdlib.h>    //abs

//more efficient way using formulae
namespace difference_of_squares {
    int square_of_sum(int numberRange){
        //formula sum 1 to n: n * (n+1) / 2
        //solution of above ^2 is square of sums
        return ((numberRange*(numberRange+1))/2)*((numberRange*(numberRange+1))/2);
    }

    int sum_of_squares(int numberRange){
        //formula to calculate: ( n * ( n + 1 ) * ( 2n + 1 ) ) / 6
        return (numberRange*(numberRange+1)*(2*numberRange+1))/6;
    }

    int difference(int numberRange){
        return abs(square_of_sum(numberRange)-sum_of_squares(numberRange));
    }
}  // namespace difference_of_squares
