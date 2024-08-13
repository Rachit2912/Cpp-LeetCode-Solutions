class Solution {
public:

void solver(int index, int targetSum, vector<int> &candidates, vector<int> &res, vector<vector<int>> &ans){

    // base case : 
    if(targetSum<0)return;
    if(targetSum == 0){
        ans.push_back(res);
        return;
    }

    for(int i = index; i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1]){continue;}
        res.push_back(candidates[i]);
        solver(i+1,targetSum-candidates[i],candidates,res,ans);
        res.pop_back();
    }

}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        // sort the candidates array for getting the elements arranged so that we'll get the idea 
        // if there are more no. of our targetSum are there or not 
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();

        vector<vector<int>> ans;
        vector<int> res;
        solver(0,target,candidates,res,ans);
        return ans;
    }
};