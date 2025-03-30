class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int idx=0;
        vector<int>temp;
        unordered_set<int>chars;
        solve(ans,nums,temp,chars);
        return ans;
    }

private:
    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> temp, unordered_set<int> &chars){

        for(int i=0; i<nums.size(); i++){

            if(temp.size()==nums.size()){ans.push_back(temp);return;}

            if(chars.find(nums[i])==chars.end()){
                temp.push_back(nums[i]);
                chars.insert(nums[i]);
                solve(ans,nums,temp,chars);
                chars.erase(nums[i]);
                temp.pop_back();
            }
        }

    }
};