class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int ans=0;
        for(auto r : grid){
            for(auto c : r){
                nums.push_back(c);
            }
        }

        int n = nums.size();
        sort(nums.begin(),nums.end());
        int target = nums[n/2];

        for(int no : nums){
            if((no-target)%x != 0)return -1;
            ans += abs(target-no)/x;
        }
        return ans;


    }
};