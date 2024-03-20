#include "resistor_color.h"

namespace resistor_color {
    const std::vector<std::string> colorList{"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};

    int color_code(const std::string& color){
        for(size_t i=0; i<colorList.size(); i++)
        {
            if(colorList[i] == color)
                return i;
        }
        return -1;
    }

    std::vector<std::string> colors(){
        return colorList;
    }
}  // namespace resistor_color
