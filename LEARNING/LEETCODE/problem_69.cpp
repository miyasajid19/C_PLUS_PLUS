class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;
        int left = 1, right = x / 2;
        int result = 0;

        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (square == x)
            {
                return mid;
            }
            else if (square < x)
            {
                result = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }
};