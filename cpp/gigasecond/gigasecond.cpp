#include "gigasecond.h"

namespace gigasecond {
    long gigasec = 1'000'000'000;

    boost::posix_time::ptime advance(boost::posix_time::ptime startTime){
        return startTime+boost::posix_time::seconds(gigasec);
    }
}  // namespace gigasecond
