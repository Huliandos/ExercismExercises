#include "pascals_triangle.h"

namespace pascals_triangle {
    std::vector<std::vector<int>> generate_rows(int rowCount){
        std::vector<std::vector<int>> rows{}; 
     
        for (int line = 0; line < rowCount; line++)
        {
            std::vector<int> row{};
            //entries per line == line number
            for (int i = 0; i <= line; i++)
            {
                //first and last values in  are 1
                if (line == i || i == 0){
                    row.push_back(1);
                    continue;
                }
                row.push_back(rows[line - 1][i - 1] + rows[line - 1][i]);
            }

            rows.push_back(row);
        }

        return rows;
    }
}  // namespace pascals_triangle
