#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace yacht {
    int score(const std::vector<int>&, const std::string&);

    int calculateSum(const std::vector<int>&, int);

    std::unordered_map<int, int> generateNumOccurences(const std::vector<int>&);
}  // namespace yacht
