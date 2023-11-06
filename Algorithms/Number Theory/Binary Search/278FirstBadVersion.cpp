/*
This is simple binary search problem...
Problem link: https://leetcode.com/problems/first-bad-version/
Time Complexity: O(log n)
*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
    long long l = 1, r = n, mid, ans;
    while (l <= r) {
        mid = (r+l) / 2;
        if (isBadVersion(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    return ans;
}
};
