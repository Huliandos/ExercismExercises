#pragma once

#include <array>
#include <string_view>

namespace kindergarten_garden {
    enum class Plants{
        clover,
        grass,
        radishes,
        violets
    };

    std::array<kindergarten_garden::Plants, 4> plants(const std::string_view&, const std::string_view&);

    void setStudentPlantAtPos(std::array<kindergarten_garden::Plants, 4>&, int, char);
}  // namespace kindergarten_garden
