class Solution 
{
public:
    bool inDatabase(char c, vector<char>& data) //judge if the char in the database
    {
        if (data.empty())
        {
            data.push_back(c);
            return false;
        }
        for (int i = 0; i< data.size();i++)
        {
            if (data.at(i) == c)
            {
                return true;
            }
        }
        data.push_back(c);
        return false;
    }
    
    int lengthOfLongestSubstring(string s) 
    {
        int max = 0;
        int count = 0;
        vector<char> database;
        
        while (!s.empty())
        {
            char c = s.front();
            if (!inDatabase(c, database))
            {
                count++;
            }
            else
            {
                
                //database.clear(); //this is wrong, we can just delete the database from front to the char which appears twice
                auto end = find(database.begin(), database.end(), c);   //find the index of the char which appears twice
                database.erase(database.begin(), end + 1);  //clear the database from front to the index which we just found
                database.push_back(c);  //push the current char into database
                
                count = database.size();    //the count = the database size
            }
            if (max < count)    //update the current max length of substring
                max = count;
            s.erase(s.begin());
        }
        //if (max < count)
        //    max = count;

        return max;
    }
};
