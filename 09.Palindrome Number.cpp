class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if (x < 0 || (x % 10 == 0 && x != 0))   //if x < 0 or the last digit of number is 0 (the number != 0), the number is not Palindrome Number
            return false;
        
        int compareNum = 0;
        while (x > compareNum)
        {
            compareNum = compareNum * 10 + x % 10;
            x /= 10;
        }
        
        if (x == compareNum || x == compareNum /10) /* when length of the integer is even, Palindrome Number can be check by */
            return true;                            /* if x == compareNum.                                                   */
        else                                        /* when length of the integer is odd, Palindrome Number can be check by  */
            return false;                           /* if x == compareNum / 10.                                              */
        }
};