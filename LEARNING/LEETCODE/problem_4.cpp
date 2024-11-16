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
