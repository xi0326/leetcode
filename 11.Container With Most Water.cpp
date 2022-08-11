class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int maxArea = 0, left = 0, right = height.size() - 1;
        while (left < right)
        {
            maxArea = max(maxArea, min(height.at(left), height.at(right)) * (right - left));    //count maxArea
            
          
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return maxArea;
    }
};