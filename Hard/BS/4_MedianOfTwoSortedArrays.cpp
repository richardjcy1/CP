class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        int left = 0, right = m;
        while (left <= right)
        {
            int x = left + (right - left) / 2;
            int y = (m + n + 1) / 2 - x;
            int xLeft = (!x) ? INT_MIN : nums1[x - 1];
            int yLeft = (!y) ? INT_MIN : nums2[y - 1];
            int xRight = (x == m) ? INT_MAX : nums1[x];
            int yRight = (y == n) ? INT_MAX : nums2[y];
            if (xLeft <= yRight && yLeft <= xRight)
            {
                if ((m + n) % 2 == 0) return (double)(max(xLeft, yLeft) + min(xRight, yRight)) * 0.5;
                return (double)max(xLeft, yLeft);
            }
            else if (xLeft > yRight) right = x - 1;
            else left = x + 1;
        }
        return -1;
    }
};