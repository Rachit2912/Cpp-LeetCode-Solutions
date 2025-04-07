class Solution {
public:
    int dp[201][20001];
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2)return false;

        return solve(0,sum/2,nums);

    }

private:
    bool solve(int idx, int target, vector<int> &nums){

        // base case :
        if(target==0)return true;
        if(target<0)return false;
        if(idx==nums.size())return false;

        if(dp[idx][target]!=-1)return dp[idx][target];

        // exploration : skip ya take
        // take :
        bool take = false;
        if(nums[idx] <= target)take = solve(idx+1,target-nums[idx],nums);

        // skip :
        auto skip = solve(idx+1,target,nums);

        return dp[idx][target]=take||skip;
    }
};