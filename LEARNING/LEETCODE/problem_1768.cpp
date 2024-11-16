class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int i = 0;
        int j = 0;
        string ans;
        bool turn = true;
        while (i < len1 and j < len2) {
            if (turn)
                ans += word1[i++];
            else
                ans += word2[j++];

            turn = !turn;
        }
        while (i < len1) {
            ans += word1[i++];
        }
        while (j < len2) {
            ans += word2[j++];
        }
        return ans;
    }
};