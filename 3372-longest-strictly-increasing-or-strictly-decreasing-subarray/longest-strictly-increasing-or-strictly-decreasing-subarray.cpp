class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int minL(1), maxL(1),ans(1);
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                maxL++;
                minL =1;
            }
            else if(nums[i]<nums[i-1]){
                minL++;
                maxL =1;
            }
            else{
                minL=1;maxL=1;
            }
            ans = max({ans,maxL,minL});
        }
        return ans;
    }
};