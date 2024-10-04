/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
class CustomStack
{
public:
    CustomStack(int maxSize)
    {
        this->array.resize(maxSize);
    }
    
    void push(int x)
    {
        if (this->idx == array.size())
            return;
        array[idx] = x;
        ++idx;
        return;
    }
    
    int pop()
    {
        --idx;
        if (idx < 0)
        {
            idx = 0;
            return -1;
        }
        return array[idx];
    }
    
    void increment(int k, int val)
    {
        for (int i = 0; i < min(int(array.size()), k); ++i)
            array[i] += val;
        return;
    }
private:
    vector<int> array;
    int idx = 0;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end

