class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto n : nums)freq[n]++;
        int n = size(nums), ans=0;
        for(int &n : nums){
            if(freq[n+1])ans = max(ans,freq[n]+freq[n+1]);
        }
        return ans;
    }
};