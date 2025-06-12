class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = abs(nums[0]-nums[nums.size()-1]);
        for(int i=0; i<size(nums)-1; i++)ans = max(ans,abs(nums[i]-nums[i+1]));
        return ans;
    }
};