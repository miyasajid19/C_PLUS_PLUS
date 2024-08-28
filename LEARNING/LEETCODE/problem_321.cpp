class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        while (n != 0) {
            if (n % 2 == 1) {
                return false;
            }
            n /= 2;
            if (n < 9 and n == 1) {
                return true;
            }
        }
        return true;
    }
};