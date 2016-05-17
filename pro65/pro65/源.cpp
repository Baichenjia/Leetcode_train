//×Ô¶¯»ú
//http://blog.csdn.net/suwei19870312/article/details/12094233

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        enum InputType
        {
            INVALID,    // 0
            SPACE,      // 1
            SIGN,       // 2
            DIGIT,      // 3
            DOT,        // 4
            EXPONENT,   // 5
            NUM_INPUTS  // 6
        };
        
        int transitionTable[][NUM_INPUTS] =
        {
            -1,  0,  3,  1,  2, -1,     // next states for state 0
            -1,  8, -1,  1,  4,  5,     // next states for state 1
            -1, -1, -1,  4, -1, -1,     // next states for state 2
            -1, -1, -1,  1,  2, -1,     // next states for state 3
            -1,  8, -1,  4, -1,  5,     // next states for state 4
            -1, -1,  6,  7, -1, -1,     // next states for state 5
            -1, -1, -1,  7, -1, -1,     // next states for state 6
            -1,  8, -1,  7, -1, -1,     // next states for state 7
            -1,  8, -1, -1, -1, -1,     // next states for state 8
        };
        
        int state = 0;
		string::iterator p = s.begin();
        while (*p != '\0')
        {
            InputType inputType = INVALID;
            if (isspace(*p))
                inputType = SPACE;
            else if (*p == '+' || *p == '-')
                inputType = SIGN;
            else if (isdigit(*p))
                inputType = DIGIT;
            else if (*p == '.')
                inputType = DOT;
            else if (*p == 'e' || *p == 'E')
                inputType = EXPONENT;
            
            state = transitionTable[state][inputType];
            
            if (state == -1)
                return false;
            else
                ++p;
        }
        
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};
