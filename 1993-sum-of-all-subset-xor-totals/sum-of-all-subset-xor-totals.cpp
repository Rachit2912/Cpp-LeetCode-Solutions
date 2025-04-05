class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        vector<vector<int>> subsets;
    generateSubsets(0, subsets, {}, nums);

    int ans = 0;
    for (auto& s : subsets) {
        int xors = 0;
        for (int n : s)
            xors ^= n;
        ans += xors;
    }
    return ans;
}

private : 
    void generateSubsets(int idx, vector<vector<int>>& subsets,
                          vector<int> temp, vector<int> nums) {

                            // base case :
                            if(idx == nums.size()){
                                subsets.push_back(temp);
                                return;
                            }

                            // explore :
                            temp.push_back(nums[idx]);
                            generateSubsets(idx+1,subsets,temp,nums);
                            //backtrack:
                            temp.pop_back();

                            // skip and explore:
                            generateSubsets(idx+1,subsets,temp,nums);

                          }
}
;