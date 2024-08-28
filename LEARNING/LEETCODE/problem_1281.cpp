class Solution {
public:
    int subtractProductAndSum(int num) {
        int sum=0;
        int product=1;
        while(num!=0)
        {
            int remainder=num%10;
            sum+=remainder;
            product*=remainder;
            num/=10;
        }
        return product-sum;
    }
};