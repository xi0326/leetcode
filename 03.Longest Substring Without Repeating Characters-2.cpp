class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left = 0, max_length = 0;
        map<char, int> database;
        
        for (int right = 0; left + max_length < s.size(); right++)  //go through the string. if left + max_length >= size of string, means we don't need to count anymore, this interval maximum won't bigger than global maximum
        {
            if (database.find(s.at(right)) != database.end())
            {
                left = max(left, database.at(s.at(right)) + 1);
            }
            database[s.at(right)] = right;  //update the index of character
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};