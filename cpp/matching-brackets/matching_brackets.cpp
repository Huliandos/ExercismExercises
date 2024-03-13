#include "matching_brackets.h"

#include <stack>
#include <set>

namespace matching_brackets {
    std::map<char, char> m_bracketsPairing = {
        { ')', '('  },
        { ']', '[' },
        { '}', '{' }
    };

    std::set<char> m_openedBrackets{'(', '[', '{'};

    bool check(std::string input){    
        std::stack<char> stack;

        for(char c : input){
            //add opening brackets to stack
            if (m_openedBrackets.find(c) != m_openedBrackets.end()){
                stack.push(c);
                continue;
            }

            auto bracketsPair = m_bracketsPairing.find(c);
            if(bracketsPair != m_bracketsPairing.end()){
                //closing bracket without opening bracket found
                if(stack.empty())
                    return false;

                //check if opening top of stack is the relevant opening bracket
                if(stack.top()==bracketsPair->second)
                    stack.pop();
                else
                    return false;
            }
        }

        return stack.empty();
    }
}  // namespace matching_brackets
