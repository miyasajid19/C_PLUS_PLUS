class Solution {
public:
    bool isPalindrome(long long int x) {
        if(x<0)
        {
            return false;
        }
        long long int temp=x;
        long long int remainder;
        long long int sum=0;
        while(temp!=0)
        {
            remainder=temp%10;
            sum=sum*10+remainder;
            temp/=10;
        }
        return sum==x;
    }
};