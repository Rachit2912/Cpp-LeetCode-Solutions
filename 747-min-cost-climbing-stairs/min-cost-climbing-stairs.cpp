class Solution {
public:

int minCost_memo(vector<int> &cost, int n, vector<int> &dp){
    // base case : 
    if(n==0) return cost[0];
    if(n==1) return cost[1];

    if(dp[n]!=-1) return dp[n];

    dp[n] = min(minCost_memo(cost,n-2,dp),
    minCost_memo(cost,n-1,dp)) + cost[n];
    return dp[n];
}

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        int ans = min(minCost_memo(cost,n-1,dp),
        minCost_memo(cost,n-2,dp));
        return ans;
    }
};