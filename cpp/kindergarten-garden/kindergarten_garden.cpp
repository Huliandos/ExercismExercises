#include "kindergarten_garden.h"

#include <stdexcept>

namespace kindergarten_garden {
    std::array<kindergarten_garden::Plants, 4> plants(const std::string_view& plantRows, const std::string_view& name){
        std::array<kindergarten_garden::Plants, 4> studentsPlants{{kindergarten_garden::Plants::clover, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::clover, kindergarten_garden::Plants::clover}};

        //first letter of name - 'A' * 2 is 0-1 for A, 2-3 for B etc.
        int plantsStartPos = (name[0]-'A')*2;
        setStudentPlantAtPos(studentsPlants, 0, plantRows[plantsStartPos]);
        setStudentPlantAtPos(studentsPlants, 1, plantRows[plantsStartPos+1]);
        
        std::size_t newlinePos = plantRows.find('\n');
        if (newlinePos == std::string::npos)
            throw std::domain_error("Invalid 'plantRows' input string");
        
        plantsStartPos += newlinePos + 1;
        setStudentPlantAtPos(studentsPlants, 2, plantRows[plantsStartPos]);
        setStudentPlantAtPos(studentsPlants, 3, plantRows[plantsStartPos+1]);
        
        return studentsPlants;
    }

    void setStudentPlantAtPos(std::array<kindergarten_garden::Plants, 4>& studentsPlants, int plantNum, char plantChar){
        switch(plantChar){
            case 'C':
                studentsPlants[plantNum] = kindergarten_garden::Plants::clover;
                break;
            case 'G':
                studentsPlants[plantNum] = kindergarten_garden::Plants::grass;
                break;
            case 'R':
                studentsPlants[plantNum] = kindergarten_garden::Plants::radishes;
                break;
            case 'V':
                studentsPlants[plantNum] = kindergarten_garden::Plants::violets;
                break;
            default:
                throw std::domain_error("Invalid plant");
        }
    }
}  // namespace kindergarten_garden
