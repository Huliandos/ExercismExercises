#include "grade_school.h"

#include <utility>
#include <iostream>

namespace grade_school {
        //setter
        void school::add(const string name, const int grade){
            vector<string> value;
            try{
                value = schoolRoster.at(grade);
                //alphabetical sorting by finding position of entry
                vector<string>::iterator it;
                for(it = begin(value); it != end(value); it++){
                    if((*it).compare(name) > 0){
                        break;
                    }
                }
                value.insert(it, name);
            }
            //catch(const out_of_range& e){
            catch(...){
                value = {name};
            }
            //schoolRoster.insert_or_assign(pair<int, vector<string>>(grade, value));
            schoolRoster[grade] = value;
        }

        //getter
        map<int, vector<string>> school::roster() const{
            return schoolRoster;
        }

        vector<string> school::grade(const int grade) const{
            vector<string> valuesAtGrade;
            try{
                valuesAtGrade = schoolRoster.at(grade);
            }
            catch(...){

            }
            return valuesAtGrade;
        }
}  // namespace grade_school
