class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x: nums)
            pq.push(x*x);
        
        vector<int>ans;
        while(not pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> result(n);
//         int left = 0, right = n - 1;
//         int pos = n - 1;  // Start filling the result array from the end
        
//         while (left <= right) {
//             int leftSquare = nums[left] * nums[left];
//             int rightSquare = nums[right] * nums[right];
            
//             if (leftSquare > rightSquare) {
//                 result[pos--] = leftSquare;
//                 left++;
//             } else {
//                 result[pos--] = rightSquare;
//                 right--;
//             }
//         }
        
//         return result;
//     }
// };
