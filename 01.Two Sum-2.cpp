class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> indexes;
        for(int i = 0;i < nums.size();i++)
            indexes[nums.at(i)] = i;
        for(int i = 0;i < nums.size();i++)
        {
            int left = target - nums.at(i);
            if(indexes.count(left) && indexes.at(left) != i)
                return{i, indexes.at(left)};
        }
        return {};
    }
};