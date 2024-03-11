#include "beer_song.h"

namespace beer_song {
    std::string verse(int verseNum){
        std::string verseNumString, verseDecreasedString;

        if(verseNum == 2){
            verseNumString = "2 bottles";
            verseDecreasedString = "1 bottle";
        }
        //different verse
        else if(verseNum == 1)
        {
            //verseNumString = "1 bottles";
            //verseDecreasedString = "no more bottles";
            return "1 bottle of beer on the wall, 1 bottle of beer.\n"
                "Take it down and pass it around, no more bottles of beer on the wall.\n";
        }
        //different verse
        else if(verseNum == 0)
        {
            return "No more bottles of beer on the wall, no more bottles of beer.\n"
                "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
        }
        else{
            verseNumString = std::to_string(verseNum) + " bottles";
            verseDecreasedString = std::to_string(verseNum-1) + " bottles";
        }
        
        std::string result = verseNumString + " of beer on the wall, " + verseNumString 
        + " of beer.\nTake one down and pass it around, " + verseDecreasedString + " of beer on the wall.\n";
        
        return result;
    }

    std::string sing(int startVerse, int endVerse){
        std::string result = "";
        for(int i=startVerse; i>=endVerse; i--){
            result += verse(i);
            if(i!=endVerse)
                result += "\n";
        }
        return result;
    }
}  // namespace beer_song
