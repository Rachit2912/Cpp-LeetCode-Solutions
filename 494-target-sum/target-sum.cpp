class Solution {
public:
        int totalSum;
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int>(2*totalSum+1,INT_MIN));
        return solve(nums,target,0,0,dp);
    }

private:
int solve(vector<int> nums, int target, int idx, int sum, vector<vector<int>> &dp){
    if(idx==nums.size()){
        if(sum==target)return 1;
        else return 0;
    }else{

        if(dp[idx][sum+totalSum] != INT_MIN){return dp[idx][sum+totalSum];}
        
        int add = solve(nums,target,idx+1,sum+nums[idx],dp);
        int sub = solve(nums,target,idx+1,sum-nums[idx],dp);

        dp[idx][sum+totalSum] = add+sub;
        return dp[idx][sum+totalSum];
    }
}
};