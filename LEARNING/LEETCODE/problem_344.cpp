class Solution {
public:
    void reverseString(vector<char>& s) {
        int i,j;
        for(int i=0;i<s.size();i++)
        {
            cout<<s[i];
        }
        for(i=0,j=s.size()-1;i<s.size()/2;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }
};