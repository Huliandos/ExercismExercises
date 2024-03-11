#include "robot_name.h"

#include <random>

namespace robot_name {
    std::random_device rand_dev;  //Will be used to obtain a seed for the random number engine
    std::mt19937 generator(rand_dev()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> distributeAscii(65, 90);    //Ascii 65-90, aka A-Z
    std::uniform_int_distribution<int> distributeNum(48, 57);    //Ascii 48-57, aka 0-9

    robot::robot(){
        generateName();
    }

    void robot::generateName(/*std::string nameBeforeReset*/){
        robotName = "-----";

        //In C++20 generatedNames.cotains() exists
        while(generatedNames.count(robotName) > 0 || robotName == "-----"){
            robotName[0] = (char)distributeAscii(generator);    //Ascii 65-90, aka A-Z
            robotName[1] = (char)distributeAscii(generator);
            robotName[2] = (char)distributeNum(generator);    //Ascii 48-57, aka 0-9
            robotName[3] = (char)distributeNum(generator);
            robotName[4] = (char)distributeNum(generator);
        }

        generatedNames.insert(robotName);
        robotName = robotName;

        //this isn't considered by the test, but should generally be possible
        /*
        if(nameBeforeReset!=""){
            //free the old robots name to be used again
            generatedNames.erase(nameBeforeReset);
        }
        */
    }

    std::string robot::name() const{
        return robotName;
    }

    void robot::reset(){
        generateName(/*robotName*/);
    }
}  // namespace robot_name
