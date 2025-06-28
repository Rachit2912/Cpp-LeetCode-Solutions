class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> temp;
        for(int i=0; i<n; i++)temp.emplace_back(i,nums[i]);

        sort(temp.begin(),end(temp),
        [&](pair<int,int> a, pair<int,int> b){
            return a.second>b.second;
        });
        sort(temp.begin(),begin(temp)+k);
        vector<int>ans;
        for(int i=0; i<k; i++)ans.push_back(temp[i].second);
        return ans;

    }
};