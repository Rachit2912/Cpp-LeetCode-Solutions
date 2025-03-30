class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, ans, temp, target, candidates);
        return ans;
    }

private:
    void solve(int idx, vector<vector<int>>& ans, vector<int>& temp, int target,
               vector<int>& candidates) {

                //base case :
                if(target==0){ans.push_back(temp);return;}
                if(idx>=candidates.size()){return;}

                //self-explore:
                if(candidates[idx]<=target){
                    temp.push_back(candidates[idx]);
                    solve(idx, ans, temp, target-candidates[idx], candidates);
                    temp.pop_back();  //backtrack
                }

                //explore:
                solve(idx+1, ans, temp,target, candidates);

    }
};