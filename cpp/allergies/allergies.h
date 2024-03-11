#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <unordered_set>
#include <vector>

namespace allergies {
    class allergy_test{
private:
        std::unordered_set<std::string> existing_allergies;
        std::vector<std::string> possible_allergies {"eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"};
public:
        allergy_test(int);
        bool is_allergic_to(std::string);
        std::unordered_set<std::string> get_allergies();
    };
}  // namespace allergies

#endif // ALLERGIES_H