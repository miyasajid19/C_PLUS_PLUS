class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for (auto x : s) {
            if (isalnum(x)) {
                ans += tolower(x);
            }
        }

        int len = ans.size();
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            if (ans[i] != ans[j]) {
                return false;
            }
        }
        return true;
    }
};
