#if !defined(SAY_H)
#define SAY_H

#include <string>
#include <map>

namespace say {

    std::string in_english(unsigned long long);
    std::string generateStringResult(const std::string&);
    std::string generateStringForTuplet(const std::string&);
    
    //helper functions
    int charToInt(char);
    bool isMinus(char);
    void segmentationViolationHandler(int);
}  // namespace say

#endif // SAY_H