class Solution 
{
public:
    int myAtoi(string s) 
    {
        int index = 0;
        bool sign = false;
        int result = 0;
        
        if (s.length() == 0)    //return 0 if string == ''
            return 0;
        
        while (index < s.length() && s.at(index) == ' ') //skip whitespace
            index++;
        
        if (index < s.length() && (s.at(index) == '+' || s.at(index) == '-'))   //check the sign
        {
            sign = s.at(index) == '-' ? true : false;
            index++;
        }
        
        while (index < s.length() && s.at(index) >= '0' && s.at(index) <= '9')  //get digit until the character is not digit
        {
            //result = result * 10 + (s.at(index) - '0');
            int overflow = 0;
            overflow = __builtin_mul_overflow(result, 10, &result); //shift left and prevent overflow
            if (overflow == 1)
                return sign ? INT_MIN : INT_MAX;
            overflow = __builtin_add_overflow(result, (s.at(index) - '0'), &result);    //add new digit into result and also prevent overflow
            if (overflow == 1)
                return sign ? INT_MIN : INT_MAX;
            
            index++;
        }
        
        return sign ? -result : result;        
    }
};