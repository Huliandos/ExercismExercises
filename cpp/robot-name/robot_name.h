#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <unordered_set>
#include <string>

namespace robot_name {
    class robot{
        inline static std::unordered_set<std::string> generatedNames;
        std::string robotName;
        void generateName(/*std::string nameBeforeReset=""*/);
public:
        robot();
        std::string name() const;
        void reset();
    };
}  // namespace robot_name

#endif // ROBOT_NAME_H