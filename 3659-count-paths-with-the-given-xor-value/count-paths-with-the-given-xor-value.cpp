class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9+7;
        int n = grid.size(),m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(20,00)));

        dp[n-1][m-1][grid[n-1][m-1]^k]=1;

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                for(int curr =0; curr<16; curr++){
                    if(i==n-1 && j==m-1)continue;

                    int newCurr = curr^grid[i][j];

                    if(j+1<m){
                        dp[i][j][curr] = (dp[i][j][curr] + dp[i][j+1][newCurr]) % MOD;
                    }

                    if(i+1<n){
                        dp[i][j][curr] = (dp[i][j][curr] + dp[i+1][j][newCurr]) % MOD;
                    }
                }
            }
        }
        return dp[0][0][0];
    }
};