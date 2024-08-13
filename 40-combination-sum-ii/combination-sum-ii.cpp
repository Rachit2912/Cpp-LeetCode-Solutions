class Solution {
public:
    void solver(int index, int targetSum, vector<int>& candidates, vector<int>& res, vector<vector<int>>& ans) {
        // Base case: If targetSum is zero, a valid combination is found
        if (targetSum == 0) {
            ans.push_back(res);
            return;
        }

        // Base case: If index exceeds the bounds or targetSum is negative, stop recursion
        if (index >= candidates.size() || targetSum < 0) return;

        // Include the current candidate and move to the next index
        res.push_back(candidates[index]);
        solver(index + 1, targetSum - candidates[index], candidates, res, ans);

        // Backtrack by removing the last added element
        res.pop_back();

        // Skip duplicates by advancing the index while the next candidate is the same as the current one
        int nextIndex = index + 1;
        while (nextIndex < candidates.size() && candidates[nextIndex] == candidates[index]) {
            nextIndex++;
        }

        // Exclude the current candidate and move to the next non-duplicate index
        solver(nextIndex, targetSum, candidates, res, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        solver(0, target, candidates, res, ans);
        return ans;
    }
};
