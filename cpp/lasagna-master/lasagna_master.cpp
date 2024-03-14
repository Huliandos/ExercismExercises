#include "lasagna_master.h"

namespace lasagna_master {

    int preparationTime(const std::vector<std::string>& layers, int averageLayerPreperationTime){
        return layers.size() * averageLayerPreperationTime;
    }

    //50g noodles per noodle layer, .2 liters sauce per sauce layer
    amount quantities(const std::vector<std::string> layers){
        amount curAmount{};

        for(std::string layer : layers){
            if(layer == "noodles"){
                curAmount.noodles += 50;
                continue;
            }
            if(layer == "sauce")
                curAmount.sauce += .2;
        }
        
        return curAmount;
    }

    void addSecretIngredient(std::vector<std::string>& myLayers, const std::vector<std::string>& otherLayers){
        myLayers[myLayers.size()-1] = otherLayers[otherLayers.size()-1];
    }

    std::vector<double> scaleRecipe(const std::vector<double>& quantities, int portionNumber){
        std::vector<double> scaled {};
        double factor = portionNumber / 2.0;
        for(double quantity : quantities)
            scaled.push_back(quantity*factor);
        return scaled;
    }

    void addSecretIngredient(std::vector<std::string>& layers, const std::string& secretIngredient){
        layers[layers.size()-1] = secretIngredient;
        
    }
}  // namespace lasagna_master
