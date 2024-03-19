#include "eliuds_eggs.h"

namespace chicken_coop {
    int positions_to_quantity(int decimal){
        int count = 0;
        while (decimal > 0) {
            count += decimal & 1;
            decimal >>= 1;
        }
        return count;
    }
}  // namespace chicken_coop
