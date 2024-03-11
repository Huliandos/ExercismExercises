#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>

namespace date_independent {
    class clock{
private:
        int minutes;
        int hours;
        clock(int, int);
public:        
        static clock at(int, int);
        clock plus(int);
        static void handleOverflows(int&, int&);
        operator std::string() const;
        bool operator ==(const clock&) const;
        bool operator !=(const clock&) const;
    };
}  // namespace date_independent

#endif // CLOCK_H