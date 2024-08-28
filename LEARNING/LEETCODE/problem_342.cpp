class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        if (n == 1)
        {
            return true;
        }
        while (n != 0)
        {
            if (n % 4 != 0)
            {
                return false;
            }
            n /= 4;
            if (n < 9 and n == 1)
            {
                return true;
            }
        }
        return true;
    }
};