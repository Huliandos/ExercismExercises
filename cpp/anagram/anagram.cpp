#include "anagram.h"

#include <cctype>
#include <algorithm>

namespace anagram {
    anagram::anagram(const std::string& word){
        m_word = strTolower(word);
        m_letterCount = generateLetterCount(m_word);
    }

    std::vector<std::string> anagram::matches(const std::vector<std::string>& words){
        std::vector<std::string> anagrams{};
        for(const std::string& word : words){
            std::string wordLowered = strTolower(word);
            if(wordLowered == m_word)
                continue;
            std::unordered_map<char, int> letterCount = generateLetterCount(wordLowered);
            if(letterCount == m_letterCount)
                anagrams.push_back(word);
        }
        return anagrams;
    }

    std::unordered_map<char, int> anagram::generateLetterCount(const std::string_view& word){
        std::unordered_map<char, int> letterCount;
        for(char c : word){
            if (auto search = letterCount.find(c); search != letterCount.end()){
                search->second++;
                continue;
            }
            letterCount[c] = 1;
        }
        return letterCount;
    }

    std::string strTolower(const std::string& str)
    {
        std::string strLowered = str;
        std::transform(strLowered.begin(), strLowered.end(), strLowered.begin(), [](unsigned char c){ return std::tolower(c); });
        return strLowered;
    }
}  // namespace anagram
