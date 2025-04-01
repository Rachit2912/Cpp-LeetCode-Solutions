class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto &n : nums)freq[n]++;

        int n = nums.size()/3;
        vector<int>ans;
        for(auto &f : freq){
            if(f.second>n)ans.push_back(f.first);
        }
        return ans;
    }
};