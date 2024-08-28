class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        while (n != 0) {
            if (n % 3 !=0) {
                return false;
            }
            n /= 3;
            if (n < 9 and n == 1) {
                return true;
            }
        }
        return true;
    }
};