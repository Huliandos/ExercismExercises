#include "yacht.h"

#include <algorithm>

namespace yacht {
    int score(const std::vector<int>& dice, const std::string& category){
        if(category == "ones")
            return calculateSum(dice, 1);
        if(category == "twos")
            return calculateSum(dice, 2);
        if(category == "threes")
            return calculateSum(dice, 3);
        if(category == "fours")
            return calculateSum(dice, 4);
        if(category == "fives")
            return calculateSum(dice, 5);
        if(category == "sixes")
            return calculateSum(dice, 6);
        
        if(category == "full house"){
            std::unordered_map<int, int> numOccurences = generateNumOccurences(dice);
            //not a possible full house
            if(numOccurences.size()!=2)
                return 0;
            int sum{0};
            
            //check for four of a kind
            for (auto& it: numOccurences) {
                if(it.second != 2 && it.second != 3)
                    return 0;
                sum += it.first * it.second;
            }
            return sum;
        }
        
        if(category == "four of a kind"){
            std::unordered_map<int, int> numOccurences = generateNumOccurences(dice);
            //four of a kind has two or one different occuring dice types
            if(numOccurences.size()>2)
                return 0;
            
            //check for four of a kind
            for (auto& it: numOccurences) {
                if(it.second >= 4)
                    return it.first * 4;
            }
            //not four of a kind
            return 0;
        }

        if(category == "little straight"){
            std::unordered_map<int, int> numOccurences = generateNumOccurences(dice);
            //straights have 5 different dice types
            if(numOccurences.size()!=5)
                return 0;
            
            //check for four of a kind
            for (auto& it: numOccurences) {
                //big straight
                if(it.first == 6)
                    return 0;
            }
            //is straight
            return 30;
        }

        if(category == "big straight"){
            std::unordered_map<int, int> numOccurences = generateNumOccurences(dice);
            //straights have 5 different dice types
            if(numOccurences.size()!=5)
                return 0;
            
            //check for four of a kind
            for (auto& it: numOccurences) {
                //little straight
                if(it.first == 1)
                    return 0;
            }
            //is straight
            return 30;
        }

        if(category == "choice"){
            int count{0};
            for(int die : dice)
                count+=die;
            return count;
        }

        if(category == "yacht"){
            //checks if all values in vector are the same
            if(std::adjacent_find(dice.begin(), dice.end(), std::not_equal_to<>() ) == dice.end() )
            {
                return 50;
            }
            return 0;
        }
        
        return -1;
    }

    int calculateSum(const std::vector<int>& dice, int dieToCount){
        int count{0};
        for(int die : dice){
            if(die == dieToCount)
                count++;
            }
        return count*dieToCount;
    }

    std::unordered_map<int, int> generateNumOccurences(const std::vector<int>& dice){
        std::unordered_map<int, int> numOccurences{};
        for(int die : dice){
            if (auto search = numOccurences.find(die); search != numOccurences.end()){
                search->second++;
                continue;
                }
            numOccurences[die] = 1;
        }
        return numOccurences;
    }
}  // namespace yacht
