#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <string>
#include <vector>
#include <string_view>
#include <unordered_map>

namespace anagram {
    class anagram{
    private:
        std::string m_word;
        std::unordered_map<char, int> m_letterCount{};
    public:
        anagram(const std::string&);
        std::vector<std::string> matches(const std::vector<std::string>&);
    private:
        std::unordered_map<char, int> generateLetterCount(const std::string_view&);
    };

    std::string strTolower(const std::string& str);
}  // namespace anagram

#endif // ANAGRAM_H