#pragma once

#include <string>
#include <string_view>

namespace rotational_cipher {
    std::string rotate(const std::string_view&, int);
}  // namespace rotational_cipher
