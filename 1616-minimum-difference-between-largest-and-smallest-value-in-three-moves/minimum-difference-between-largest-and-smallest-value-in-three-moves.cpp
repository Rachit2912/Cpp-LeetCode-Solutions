class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n <= 4) return 0;
        int minDiff = INT_MAX;

        for(int left = 0,right = n-4; right<n; left++,right++){
            minDiff = min(minDiff,nums[right]-nums[left]);
        }
        return minDiff;

    }
};