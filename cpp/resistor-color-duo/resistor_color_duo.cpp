#include "resistor_color_duo.h"

#include <map>

namespace resistor_color_duo {
    const std::map<std::string, int> colorList{{"black", 0},
        {"brown", 1},
        {"red", 2},
        {"orange", 3},
        {"yellow", 4},
        {"green", 5},
        {"blue", 6},
        {"violet", 7},
        {"grey", 8},
        {"white", 9}
    };

    int value(const std::vector<std::string>& colors){
        if(colors.size()<2)
            return -1;

        return colorList.at(colors[0]) * 10 + colorList.at(colors[1]);
    }
}  // namespace resistor_color_duo
