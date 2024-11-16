class Solution {
public:
    void merge(const vector<int>& nums1, const vector<int>& nums2, vector<int>& merged) {
        // Merging in sorted manner
        int i = nums1.size();
        int j = nums2.size();
        int k = 0;
        int l = 0;
        while (k < i && l < j) {
            if (nums1[k] < nums2[l]) {
                merged.push_back(nums1[k]);
                k++;
            } else {
                merged.push_back(nums2[l]);
                l++;
            }
        }
        while (k < i) {
            merged.push_back(nums1[k]);
            k++;
        }
        while (l < j) {
            merged.push_back(nums2[l]);
            l++;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        merge(nums1, nums2, merged);
        int n = merged.size();
        if (n % 2 == 1)
            return merged[n / 2];
        else
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
};
//############# the code should be as ######################---> time complexity should be as of log(m+n) but mine was n

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         // Ensure nums1 is the smaller array for binary search
//         if (nums1.size() > nums2.size())
//             return findMedianSortedArrays(nums2, nums1);

//         int m = nums1.size();
//         int n = nums2.size();
//         int half_len = (m + n + 1) / 2;
        
//         int left = 0, right = m;
//         while (left <= right) {
//             int i = (left + right) / 2;
//             int j = half_len - i;

//             int nums1_left_max = (i == 0) ? INT_MIN : nums1[i - 1];
//             int nums1_right_min = (i == m) ? INT_MAX : nums1[i];
//             int nums2_left_max = (j == 0) ? INT_MIN : nums2[j - 1];
//             int nums2_right_min = (j == n) ? INT_MAX : nums2[j];

//             if (nums1_left_max <= nums2_right_min && nums2_left_max <= nums1_right_min) {
//                 // Correct partition found
//                 if ((m + n) % 2 == 1) {
//                     return max(nums1_left_max, nums2_left_max);
//                 } else {
//                     return (max(nums1_left_max, nums2_left_max) + min(nums1_right_min, nums2_right_min)) / 2.0;
//                 }
//             } else if (nums1_left_max > nums2_right_min) {
//                 // Move left in nums1
//                 right = i - 1;
//             } else {
//                 // Move right in nums1
//                 left = i + 1;
//             }
//         }

//         throw invalid_argument("Input arrays are not sorted.");
//     }
// };
