class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return xorsum(0,nums,0);
    }

private:
    int xorsum(int idx, vector<int> nums, int currXOR){
        
        // base case:
        if(idx==nums.size())return currXOR;

        int noskip = xorsum(idx+1,nums,currXOR^nums[idx]);
        int skip = xorsum(idx+1,nums,currXOR);

        return (noskip+skip);
    }
};