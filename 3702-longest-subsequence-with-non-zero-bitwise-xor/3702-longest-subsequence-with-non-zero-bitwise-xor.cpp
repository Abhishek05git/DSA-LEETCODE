class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            xr ^= x;
            if (x != 0)
                hasNonZero = true;
        }

        // Every element is 0, so every subsequence has XOR 0.
        if (!hasNonZero)
            return 0;

        // Entire array has non-zero XOR.
        if (xr != 0)
            return n;

        // Remove any non-zero element.
        return n - 1;
    }
};