#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    // Ensure nums1 is the smaller array
    if (m > n) {
        return findMedianSortedArrays(nums2, n, nums1, m);
    }

    int low = 0, high = m;
    int totalLeft = (m + n + 1) / 2;

    while (low <= high) {
        int i = (low + high) / 2;      // partition in nums1
        int j = totalLeft - i;         // partition in nums2

        int left1  = (i == 0) ? INT_MIN : nums1[i - 1];
        int right1 = (i == m) ? INT_MAX : nums1[i];

        int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
        int right2 = (j == n) ? INT_MAX : nums2[j];

        if (left1 <= right2 && left2 <= right1) {
            // Correct partition
            if ((m + n) % 2 == 0) {
                return ( (double)(left1 > left2 ? left1 : left2)
                       + (double)(right1 < right2 ? right1 : right2) ) / 2.0;
            } else {
                return (double)(left1 > left2 ? left1 : left2);
            }
        }
        else if (left1 > right2) {
            high = i - 1;
        }
        else {
            low = i + 1;
        }
    }

    return 0.0; // Should never reach here
}
