class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int r(0),maxBeauty(0);

        for(int l =0; l<nums.size(); l++){
            while(r<nums.size() && nums[r]<=nums[l]+2*k)r++ ; 

            maxBeauty = max(maxBeauty,r-l);
        }
        return maxBeauty;
    }
};