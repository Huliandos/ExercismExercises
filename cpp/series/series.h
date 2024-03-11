#if !defined(SERIES_H)
#define SERIES_H

#include <vector>
#include <string_view>

namespace series {
    std::vector<int> digits(std::string_view);
    std::vector<std::vector<int>> slice(std::string_view, size_t);
}  // namespace series

#endif // SERIES_H