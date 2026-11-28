class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int onelen = nums1.size();
        int twolen = nums2.size();

        if (onelen > twolen) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int partlen = (onelen + twolen) / 2;

        int l = 0;
        int r = onelen;

        bool even = (onelen + twolen) % 2 == 0;

        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = partlen - i;

            int nums1left = i == 0 ? INT_MIN : nums1[i - 1];
            int nums1right = i == onelen ? INT_MAX : nums1[i];

            int nums2left = j == 0 ? INT_MIN : nums2[j - 1];
            int nums2right = j == twolen ? INT_MAX : nums2[j];

            if (nums1left <= nums2right && nums2left <= nums1right) {
                if (even) {
                    return (max(nums1left, nums2left) +
                            min(nums1right, nums2right)) / 2.0;
                } else {
                    return min(nums1right, nums2right);
                }
            } else if (nums1left > nums2right) {
                r = i - 1;
            } else if (nums2left > nums1right) {
                l = i + 1;
            }
        }

        return 0.0;
    }
};