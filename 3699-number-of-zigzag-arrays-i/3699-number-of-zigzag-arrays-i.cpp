class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m), down(m);

        // Length = 2
        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - i - 1;
        }

        vector<long long> newUp(m), newDown(m);
        vector<long long> prefix(m), suffix(m);

        for (int len = 3; len <= n; len++) {

            prefix[0] = down[0];
            for (int i = 1; i < m; i++)
                prefix[i] = (prefix[i - 1] + down[i]) % MOD;

            suffix[m - 1] = up[m - 1];
            for (int i = m - 2; i >= 0; i--)
                suffix[i] = (suffix[i + 1] + up[i]) % MOD;

            for (int i = 0; i < m; i++) {
                newUp[i] = (i == 0) ? 0 : prefix[i - 1];
                newDown[i] = (i == m - 1) ? 0 : suffix[i + 1];
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};