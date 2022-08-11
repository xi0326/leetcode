class Solution 
{
public:
    int reverse(int x) 
    {
        if (x == 0)
            return 0;
        else
        {
            string x_str = to_string(x);
            if (x < 0)  //delete '-' if x < 0
            {
                x_str.erase(x_str.begin());
            }
            ::reverse(x_str.begin(), x_str.end());  //reverse the string, add :: to use reverse function from algorithm
            if (x < 0)  //put '-' back if x < 0
            {
                x_str.insert(x_str.begin(), '-');
            }
            
            try //convert string back to integer
            {
                x = stoi(x_str);
            }
            catch(exception)    //avoid overflow
            {
                return 0;
            }
        }
        return x;
    }
};
