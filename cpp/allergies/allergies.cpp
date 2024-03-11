#include "allergies.h"

#include <iostream>

namespace allergies {
        allergy_test::allergy_test(int score){
            for(int i=0; i<8; i++){
                //if kth bit of n == 1
                /*
                short for:

                int mask =  1 << k;
                int masked_n = n & mask;
                int thebit = masked_n >> k;
                */
                if(((score & ( 1 << i )) >> i) == 1){
                    existing_allergies.insert(possible_allergies[i]);
                }
            }
        }

        bool allergy_test::is_allergic_to(std::string ingredient){
            auto search = existing_allergies.find(ingredient);
            //found
            if (search != existing_allergies.end())
                return true;
            
            //not found
            return false;
        }

        std::unordered_set<std::string> allergy_test::get_allergies(){
            return existing_allergies;
        }
}  // namespace allergies
