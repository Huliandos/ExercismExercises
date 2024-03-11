#include "clock.h"

namespace date_independent {        
    clock::clock(int hours, int minutes){
        this->minutes = minutes;
        this->hours = hours;
    }

    clock clock::at(int hours, int minutes){
        handleOverflows(hours, minutes);
        
        return clock(hours, minutes);
    }

    clock clock::plus(int minutesToAdd){
        minutes+=minutesToAdd;
        handleOverflows(hours, minutes);

        return *this;
    }

    void clock::handleOverflows(int& hours, int& minutes){
        //minutes overflow into hours
        hours += minutes/60;

        //minutes positive overflow
        minutes = minutes%60;

        //minutes negative overflow
        //negative minutes always substract an additional hour
        if(minutes<0){
            hours -= 1;
            minutes = 60 + minutes;
        }
        
        //positive hours overflow
        hours %= 24;

        //negative hours overflow
        if(hours < 0)
            hours = 24 + hours;
    }

    clock::operator std::string() const{
        std::string resultString = "";
        if(hours < 10)
            resultString += "0";
        resultString += std::to_string(hours) + ":";
        
        if(minutes < 10)
            resultString += "0";
        resultString += std::to_string(minutes);
        
        return resultString;
    }

    bool clock::operator ==(const clock& otherClock) const {
        if(minutes == otherClock.minutes && hours == otherClock.hours)
            return true;
        return false;
    }

    bool clock::operator !=(const clock& otherClock) const {
        if(minutes != otherClock.minutes || hours != otherClock.hours)
            return true;
        return false;
    }
}  // namespace date_independent
