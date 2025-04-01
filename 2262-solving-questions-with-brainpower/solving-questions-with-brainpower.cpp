class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long>dp(n+1,0);
        for(int i=n-1; i>=0; i--){
            int pts = q[i][0], jump = q[i][1];
            int nextQues = min(n,i+jump+1);
            dp[i] = max(dp[i+1],pts+dp[nextQues]);
        }
        return dp[0];
    }
};