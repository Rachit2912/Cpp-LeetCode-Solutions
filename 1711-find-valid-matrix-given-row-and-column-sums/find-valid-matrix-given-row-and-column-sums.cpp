class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r = rowSum.size(); int c = colSum.size();
        vector<vector<int>> ans(r,vector<int>(c,0));
        int i =0, j=0;

        while(i<r && j<c){
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
                rowSum[i] == 0 ? i++ : j++ ;
        }
        return ans;
    }
};