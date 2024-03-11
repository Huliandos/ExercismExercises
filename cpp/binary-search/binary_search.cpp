#include "binary_search.h"

#include <stdexcept>

namespace binary_search {
    size_t find(std::vector<int> data, int valueToFind){
        if(data.empty())
            throw std::domain_error("Can't search empty data");

        try{
            return findRecursively(data, valueToFind, 0, data.size()-1);
        }
        catch(const std::domain_error& e){
            throw e;
        }
    }

    size_t findRecursively(std::vector<int>& data, int valueToFind, size_t lowerBound, size_t upperBound){
        size_t middle = (lowerBound+upperBound)/2;

        //return if value found
        if(data[middle]==valueToFind)
            return middle;
        
        //recursively return search in right half of vector
        if(data[middle]<valueToFind){
            //can't look to the right of max value
            if(middle == upperBound)
                throw std::domain_error("ValueToFind extends max val");
            return findRecursively(data, valueToFind, middle+1, upperBound);
        }
        
        //recursively return search in left half of vector   
        //can't look to the left of min value   
        if(middle == lowerBound)
            throw std::domain_error("ValueToFind lower min val");
        
        return findRecursively(data, valueToFind, lowerBound, middle-1);
    }
}  // namespace binary_search
