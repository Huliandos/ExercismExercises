#include "phone_number.h"

#include <stdexcept>

namespace phone_number {
    phone_number::phone_number(std::string phoneNumber){
        //extract phone number
        for(char c:phoneNumber){
            //if c is a number
            if(c>='0' && c<='9')
                phoneNumber_.push_back(c);
        }

        //too short
        if(phoneNumber_.size()<10)
            throw std::domain_error("number too short");

        //too long
        if(phoneNumber_.size()>10){
            //invalid country code
            if(phoneNumber_[0]!='1')
                throw std::domain_error("invalid country code");

            //valid country code -> remove prefix
            phoneNumber_.erase(0, 1);
        }

        //invalid first digit of area code
        if(phoneNumber_[0]<'2')
            throw std::domain_error("invalid area code");

        //invalid first digit of exchange code
        if(phoneNumber_[3]<'2')
            throw std::domain_error("invalid exchange code");
    }

    std::string phone_number::number() const{
        return phoneNumber_;
    }

    std::string phone_number::area_code() const{
        return phoneNumber_.substr(0, 3);
    }

    phone_number::operator std::string() const{
        return '(' + area_code() + ") " + phoneNumber_.substr(3, 3) + '-' + phoneNumber_.substr(6);
    }
}  // namespace phone_number
