class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n =nums.size();
        int diffMax=0,iMax=0;
        long long ans=0;
        for(int k=0; k<n; k++){
            ans = max(ans,(long long)diffMax*nums[k]);
            diffMax=max(diffMax,iMax-nums[k]);
            iMax = max(iMax,nums[k]);
        }
        return ans;
    }
};