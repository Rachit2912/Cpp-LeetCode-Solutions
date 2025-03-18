class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0,j=0,ans=1;
        int n = nums.size();

        int mask=0;
        while(j<n){
            while((nums[j] & mask)!=0){
                mask ^= nums[i];
                i++;
            }
            ans = max(ans,j-i+1);
            mask |= nums[j];
            j++;
        }
        return ans;
    }
};