#include "doctor_data.h"
//#include <algorithm>

heaven::Vessel::Vessel(std::string name, int generation){
    this->name = name;
    this->generation = generation;
    current_system = star_map::System::Sol;
}

heaven::Vessel::Vessel(std::string name, int generation, star_map::System system){
    this->name = name;
    this->generation = generation;
    current_system = system;
}

heaven::Vessel heaven::Vessel::replicate(std::string name){
    return Vessel{name, generation+1, current_system};
}

void heaven::Vessel::make_buster(){
    busters++;
}

bool heaven::Vessel::shoot_buster(){
    if(busters == 0)
        return false;
    busters--;
    return true;;
}

std::string heaven::get_older_bob(Vessel vessel1, Vessel vessel2){
    if(vessel1.generation < vessel2.generation)
        return vessel1.name;
    return vessel2.name;
}

bool heaven::in_the_same_system(Vessel vessel1, Vessel vessel2){
    return vessel1.current_system == vessel2.current_system;
}