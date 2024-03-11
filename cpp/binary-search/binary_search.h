#if !defined(BINARY_SEARCH_H)
#define BINARY_SEARCH_H

#include <vector>

namespace binary_search {
    size_t find(std::vector<int>, int);
    size_t findRecursively(std::vector<int>&, int, size_t, size_t);
}  // namespace binary_search

#endif // BINARY_SEARCH_H