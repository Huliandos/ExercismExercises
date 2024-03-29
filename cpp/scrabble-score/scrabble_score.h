#if !defined(SCRABBLE_SCORE_H)
#define SCRABBLE_SCORE_H

#include <string_view>

namespace scrabble_score {
    int score(const std::string_view&);
}  // namespace scrabble_score

#endif // SCRABBLE_SCORE_H