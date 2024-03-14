#pragma once

#include <vector>
#include <string>

namespace lasagna_master {

    struct amount {
        int noodles;
        double sauce;
    };

    int preparationTime(const std::vector<std::string>& layers, int averageLayerPreperationTime = 2);

    amount quantities(const std::vector<std::string> layers);

    void addSecretIngredient(std::vector<std::string>& myLayers, const std::vector<std::string>& otherLayers);

    std::vector<double> scaleRecipe(const std::vector<double>& quantities, int portionNumber);

    void addSecretIngredient(std::vector<std::string>& layers, const std::string& secretIngredient);
}  // namespace lasagna_master
