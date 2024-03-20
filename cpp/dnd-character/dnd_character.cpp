#include "dnd_character.h"

#include <cmath>
#include <random>
#include <vector>
#include <algorithm> 

namespace dnd_character {
    int modifier(int diceScore){
        return static_cast<int>(std::floor((diceScore-10)/2.0));
    }

    int ability(){
        //roll the dice
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(1, 6); // define the range

        std::vector<int> diceThrows{};
        for(int i=0; i<4; i++)
            diceThrows.push_back(distr(gen)); // generate numbers

        //remove worst die
        auto min = min_element(diceThrows.begin(), diceThrows.end()); 
        diceThrows.erase(min);
        
        int sum{0};
        for(int die : diceThrows)
            sum+= die;
        return sum;
    }

    Character::Character(){
        strength = ability();
        dexterity = ability();
        constitution = ability();
        intelligence = ability();
        wisdom = ability();
        charisma = ability();

        hitpoints = 10 + modifier(constitution);
    }
}  // namespace dnd_character
