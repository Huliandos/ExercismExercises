#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <string>

namespace phone_number {
    class phone_number{
private:
        std::string phoneNumber_;
public:
        phone_number(std::string);
        std::string number() const;
        std::string area_code() const;
        operator std::string() const;
    };
}  // namespace phone_number

#endif // PHONE_NUMBER_H