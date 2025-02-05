class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s(0), e(nums.size()), m;
        if(target>nums[e-1])return e;
        while(s<=e){
            m= s+(e-s)/2;
            if(nums[m]==target)return m;
            if(target<nums[m])e=m-1;
            else s=m+1;
        }
        return s;
    }
};