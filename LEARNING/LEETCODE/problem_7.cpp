#include <climits>

class Solution {
public:
    int reverse(int x) {
        int num = 0;
        while (x != 0) {
            int lastdigit = x % 10;

            // Check for overflow: if `num` is outside the safe range
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && lastdigit > 7)) return 0;
            if (num < INT_MIN / 10 || (num == INT_MIN / 10 && lastdigit < -8)) return 0;

            num = num * 10 + lastdigit;
            x /= 10;
        }
        return num;
    }
};
