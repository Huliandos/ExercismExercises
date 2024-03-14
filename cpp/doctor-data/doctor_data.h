#pragma once

#include <string>

namespace star_map{
    enum class System{
        Sol,
        AlphaCentauri,
        BetaHydri,
        DeltaEridani,
        EpsilonEridani,
        Omicron2Eridani
    };
}

namespace heaven{
    class Vessel{
    //variables
    public:
        int generation;
        star_map::System current_system;
        int busters;
        std::string name;
    private:
    //methods
    public:
        Vessel(std::string name, int generation);
        Vessel(std::string name, int generation, star_map::System);
        Vessel replicate(std::string name);
        void make_buster();
        bool shoot_buster();
    private:
        
    };

    std::string get_older_bob(Vessel, Vessel);
    bool in_the_same_system(Vessel, Vessel);
}