class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp = nums1;
        nums1.clear();
        int i = 0;
        int j = 0;
        while (i < m and j < n) {
            if (temp[i] < nums2[j]) {
                nums1.push_back(temp[i++]);
            } else {
                nums1.push_back(nums2[j++]);
            }
        }

        while (i < m) {
            nums1.push_back(temp[i++]);
        }

        while (j < n) {
            nums1.push_back(nums2[j++]);
        }

    }
};
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = m - 1; // Pointer for the end of nums1's initial elements
//         int j = n - 1; // Pointer for the end of nums2
//         int k = m + n - 1; // Pointer for the end of nums1's full capacity

//         // Merge in reverse order, starting from the back
//         while (i >= 0 && j >= 0) {
//             if (nums1[i] > nums2[j]) {
//                 nums1[k--] = nums1[i--];
//             } else {
//                 nums1[k--] = nums2[j--];
//             }
//         }

//         // If there are remaining elements in nums2, copy them
//         while (j >= 0) {
//             nums1[k--] = nums2[j--];
//         }
//     }
// };
