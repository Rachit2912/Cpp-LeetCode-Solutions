class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int maxDiff=0, iMax=0;
        for(int k=0; k<nums.size(); k++){
            ans = max(ans,(long long)nums[k]*maxDiff);
            maxDiff = max(maxDiff,iMax-nums[k]);
            iMax = max(iMax,nums[k]);
        }
        return ans;
    }
};