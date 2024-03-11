#include "space_age.h"

namespace space_age {
    float space_age::seconds_to_days(long int seconds) const{
        return seconds/60.0f/60/24;
    }

    space_age::space_age(long int seconds){
        this->secs = seconds;
    }
    
    long int space_age::seconds() const{
        return secs;
    }
    
    float space_age::on_earth() const{
        return seconds_to_days(secs)/365.25f;
    }
    
    float space_age::on_mercury() const{
        return seconds_to_days(secs)/(365.25f*0.2408467f);
    }
    
    float space_age::on_venus() const{
        return seconds_to_days(secs)/(365.25f*0.61519726f);
    }
    
    float space_age::on_mars() const{
        return seconds_to_days(secs)/(365.25f*1.8808158f);
    }
    
    float space_age::on_jupiter() const{
        return seconds_to_days(secs)/(365.25f*11.862615f);
    }
    
    float space_age::on_saturn() const{
        return seconds_to_days(secs)/(365.25f*29.447498f);
    }
    
    float space_age::on_uranus() const{
        return seconds_to_days(secs)/(365.25f*84.016846f);
    }
    
    float space_age::on_neptune() const{
        return seconds_to_days(secs)/(365.25f*164.79132f);
    }
}  // namespace space_age
