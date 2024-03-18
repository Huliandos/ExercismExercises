#if !defined(ISOGRAM_H)
#define ISOGRAM_H

#include <string_view>

namespace isogram {
    bool is_isogram(const std::string_view&);
}  // namespace isogram

#endif // ISOGRAM_H