class Solution
{
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int min_value = arrays[0][0];
        int max_value = arrays[0].back();
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); ++i)
        {
            int current_min = arrays[i][0];
            int current_max = arrays[i].back();

            max_distance = max(max_distance, abs(max_value - current_min));
            max_distance = max(max_distance, abs(min_value - current_max));

            min_value = min(min_value, current_min);
            max_value = max(max_value, current_max);
        }

        return max_distance;
    }
};