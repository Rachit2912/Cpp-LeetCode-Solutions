class Solution {
public: 
        // space optimization : 
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev0 = cost[0];
        int prev1 = cost[1];

        for(int i =2;i<n;i++){
            int curr = cost[i] + min(prev0,prev1);
            prev0 = prev1;
            prev1 = curr;
        }
        return min(prev0,prev1);
    }
};