class Solution {
public:
    int solve(int idx, vector<int> nums, vector<int> &dp){
        if(idx>=nums.size())return 0;

        if(dp[idx]!=-1)return dp[idx];

        int pick = nums[idx]+solve(idx+2,nums,dp);
        int skip = solve(idx+1,nums,dp);

        return dp[idx]=max(pick,skip);

    }
    int rob(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
    }
};