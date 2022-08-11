class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.empty())  //check if nums1 is empty, if yes, just return the medium of nums2
        {
            if (nums2.size() % 2 == 0)
                return (nums2[(nums2.size() + 1) / 2 - 1] + nums2[(nums2.size() + 1) / 2]) / 2.0;
            else
                return double(nums2[(nums2.size() + 1) / 2 - 1]);
        }
        if (nums2.empty())  //check if nums1 is empty, if yes, just return the medium of nums1
        {
            if (nums1.size() % 2 == 0)
                return (nums1[(nums1.size() + 1) / 2 - 1] + nums1[(nums1.size() + 1) / 2]) / 2.0;
            else
                return double(nums1[(nums1.size() + 1) / 2 - 1]);
        }
           
        int length = nums1.size() + nums2.size();
        int sortedArray[length];    //declare the merged array
        auto ptr1 = nums1.begin(), ptr2 = nums2.begin();
        bool end1 = false, end2 = false;
        for (int i = 0;i < length; i++) //merge two arrays 
        {
            if (!end1 && *ptr1 <= *ptr2)
            {
                sortedArray[i] = *ptr1;
                ptr1++;
                
            }
            else if (!end2 && *ptr1 > *ptr2)
            {
                sortedArray[i] = *ptr2;
                ptr2++;
            }
            end1 = ptr1 == nums1.end() ? true : false;
            end2 = ptr2 == nums2.end() ? true : false;
            if (end1)   //if nums1 is full merged to merged array
            {
                i++;
                while (ptr2 != nums2.end())
                {
                    sortedArray[i++] = *ptr2;
                    ptr2++;
                }
                break;
            }
            if (end2)   //if nums2 is full merged to merged array
            {
                i++;
                while (ptr1 != nums1.end())
                {
                    sortedArray[i++] = *ptr1;
                    ptr1++;
                }
                break;
            }
        }

        if (length % 2 == 0)
            return (sortedArray[(length + 1) / 2 - 1] + sortedArray[(length + 1) / 2]) / 2.0;
        else
            return double(sortedArray[(length + 1) / 2 - 1]);
    }
};