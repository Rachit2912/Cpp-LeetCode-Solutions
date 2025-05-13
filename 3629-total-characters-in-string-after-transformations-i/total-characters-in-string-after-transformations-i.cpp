class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> dp;

    int dfs(char ch, int t) {
        if (t == 0) return 1;
        int idx = ch - 'a';
        if (dp[idx][t] != -1) return dp[idx][t];

        if (ch == 'z') {
            // 'z' becomes 'a' and 'b', then we apply t-1 transformations to both
            long long left = dfs('a', t - 1);
            long long right = dfs('b', t - 1);
            return dp[idx][t] = (left + right) % mod;
        } else {
            return dp[idx][t] = dfs(ch + 1, t - 1);
        }
    }

    int lengthAfterTransformations(string s, int t) {
        dp = vector<vector<int>>(26, vector<int>(t + 1, -1));
        long long total = 0;

        for (char ch : s) {
            total = (total + dfs(ch, t)) % mod;
        }

        return total;
    }
};
