#pragma once

#include <string_view>
#include <string>

namespace run_length_encoding {
    std::string encode(const std::string_view&);
    std::string decode(const std::string_view&);
}  // namespace run_length_encoding
