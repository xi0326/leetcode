class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)   //if numRows == 1, the converted string would not change
                return s;
        else
        {
            vector<string> temp_string_set(numRows);
            auto ptr = s.begin();   //set the pointer to point the first address of the input string
            int count = 0;
            while (count < s.size())
            {
                for (int i = 0;i < numRows;i++)
                {
                    if (count == s.size())
                        break;
                    temp_string_set.at(i).push_back(*ptr);
                    count++;
                    ptr++;
                    
                }

                for (int i = numRows - 2;i > 0;i--)
                {
                    if (count == s.size())
                        break;
                    temp_string_set.at(i).push_back(*ptr);
                    count++;
                    ptr++;
                }
                
            }
            
            string converted;
            for (string temp : temp_string_set)
                converted = converted + temp;
            
            return converted;
            
        }
        
    }
};
