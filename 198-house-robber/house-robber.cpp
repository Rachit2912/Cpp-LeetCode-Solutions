class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        int prev=nums[0],prev2=max(nums[0],nums[1]);
        int curr =0;
        for(int i=2; i<n; i++){
            curr=max(prev2,prev+nums[i]);
            prev=prev2;
            prev2=curr;
        }
        return prev2;

    }
};