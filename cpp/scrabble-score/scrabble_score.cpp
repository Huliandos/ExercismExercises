#include "scrabble_score.h"

#include <cctype>
#include <map>

namespace scrabble_score {
    const std::map<char, int> m_letterScorePairs {
        {'A', 1},
        {'B', 3},
        {'C', 3},
        {'D', 2},
        {'E', 1},
        {'F', 4},
        {'G', 2},
        {'H', 4},
        {'I', 1},
        {'J', 8},
        {'K', 5},
        {'L', 1},
        {'M', 3},
        {'N', 1},
        {'O', 1},
        {'P', 3},
        {'Q', 10},
        {'R', 1},
        {'S', 1},
        {'T', 1},
        {'U', 1},
        {'V', 4},
        {'W', 4},
        {'X', 8},
        {'Y', 4},
        {'Z', 10}
    };

    int score(const std::string_view& word){
        int sum = 0;
        
        for(char letter : word){
            letter = toupper(letter);
            if(letter < 'A' || letter > 'Z')
                return -1;
            
            sum += (*m_letterScorePairs.find(letter)).second;
        }

        return sum;
    }
}  // namespace scrabble_score
