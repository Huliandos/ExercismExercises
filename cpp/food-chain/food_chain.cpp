#include "food_chain.h"

namespace food_chain {
    std::string animals[] = {"fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"};
    std::string specialPhrases[] = {"",
        "It wriggled and jiggled and tickled inside her.\n",
        "How absurd to swallow a bird!\n",
        "Imagine that, to swallow a cat!\n",
        "What a hog, to swallow a dog!\n",
    	"Just opened her throat and swallowed a goat!\n",
        "I don't know how she swallowed a cow!\n",
        "She's dead, of course!\n"};

    std::string verse(int verseNum){
        std::string result;
        
        //Song is indexing from 1, arrays from 0
        verseNum-=1;
        result += "I know an old lady who swallowed a " + animals[verseNum] + ".\n";
        result += specialPhrases[verseNum];

        //horse verse
        if(verseNum==7)
            return result;
        
        while(verseNum > 0){
            result += "She swallowed the " + animals[verseNum] + " to catch the " + animals[verseNum-1];
            
            if(verseNum==2)
                result += " that wriggled and jiggled and tickled inside her";
            result += ".\n";

            verseNum--;
        }

        result += "I don't know why she swallowed the fly. Perhaps she'll die.\n";
        
        return result;
    }

    std::string verses(int fromVerse, int toVerse){
        std::string result;
        for(int i=fromVerse; i<=toVerse; i++){
            result += verse(i) + "\n";
        }
        return result;
    }

    std::string sing(){
        return verses(1, 8);
    }
}  // namespace food_chain
