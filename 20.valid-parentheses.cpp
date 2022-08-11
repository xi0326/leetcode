/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution 
{
public:
    bool isValid(string str) 
    {
        stack<char> theStack;
        
        for (char c : str)
        {
            if (c == '(' || c == '[' || c == '{')
                theStack.push(c);
            
            else
            {
                if (theStack.empty())   //it means the current char is ')', ']' or '}' but nothing can be popped
                    return false;

                if (c == ')' && theStack.top() != '(')
                    return false;

                if (c == ']' && theStack.top() != '[')
                    return false;

                if (c == '}' && theStack.top() != '{')
                    return false;

                theStack.pop();
            }
        }

        return theStack.empty();    //if stack is empty, means the string is vaild
    }
};
// @lc code=end

