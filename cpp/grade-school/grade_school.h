#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

using namespace std;

#include <string>
#include <vector>
#include <map>

namespace grade_school {
    class school{
private:
        map<int, vector<string>> schoolRoster;
public:
        //setter
        void add(string name, int grade);
        //getter
        map<int, vector<string>> roster() const;
        vector<string> grade(int grade) const;

    };
}  // namespace grade_school

#endif // GRADE_SCHOOL_H