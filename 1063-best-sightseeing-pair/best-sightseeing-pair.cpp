class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> maxLeft(n);
        maxLeft[0] = values[0];
        int ans =0;
        for(int i=1; i<n; i++){
            ans = max(ans,maxLeft[i-1]+values[i]-i);
            maxLeft[i] = max(maxLeft[i-1],values[i]+i);
        }
        return ans;
    }
};