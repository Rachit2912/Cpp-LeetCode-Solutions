class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = 1e5, maxi = -1e5;
        int diff = 0; int n = arrays.size();
        for(auto i : arrays){
            int curr_min = i[0];
            int s = i.size();
            int curr_max = i[s-1];
            diff = max(diff,max(maxi-curr_min,curr_max-mini));
            mini = min(mini,curr_min);
            maxi = max(maxi,curr_max);
        }

        return diff;
    }
};