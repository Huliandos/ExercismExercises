#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H

#include <map>
#include <string>

namespace word_count {
    std::map<std::string, int> words(std::string);
    void convertToLower(std::string&);
}  // namespace word_count

#endif // WORD_COUNT_H