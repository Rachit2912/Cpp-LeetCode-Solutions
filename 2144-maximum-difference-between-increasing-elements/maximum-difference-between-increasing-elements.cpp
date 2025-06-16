class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff=-1,minElt=nums[0],n=nums.size();
        for(int j=1; j<n; j++){
            if(minElt < nums[j]){
                maxDiff = max(maxDiff,nums[j]-minElt);
            }
            minElt=min(minElt,nums[j]);
        }
        return maxDiff;

    }
};