class Solution 
{
public:
    string longestPalindrome(string s) //dynamic programming
    {
        const int STRING_LENGTH = s.size();
        bool table[STRING_LENGTH][STRING_LENGTH];
        int front = 0, max_length = 1;
        for (int i = 0;i < STRING_LENGTH; i++)  //initalise the table
            memset(table[i], false, STRING_LENGTH * sizeof(bool));
        
        if (s.empty())
            return "";
        
        else
        {
            for (int i = 0;i < STRING_LENGTH; i++)
            {
                table[i][i] = true; //one word should be palindrome F(i,i) = true
                
                for (int j = 0;j < i; j++)
                {
                    table[j][i] = (s.at(i) == s.at(j) && (table[j + 1][i - 1] || i == j + 1));  //if F(i+1,j-1) = true && S[i] == S[j], F(i,j) = true. if S[i] == S[i+1], F(i,i+1) = true.

                    if (table[j][i] && (max_length < abs(i - j) + 1))
                    {
                        max_length = abs(i - j) + 1;
                        front = j;
                    }
                }
            }
        }
        
        return s.substr(front, max_length); //return the substring
    }
};
