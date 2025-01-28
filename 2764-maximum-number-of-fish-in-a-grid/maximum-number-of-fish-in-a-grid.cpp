class Solution {
public:
int dfs(int i, int j, vector<vector<int>>& grid){
    int fishes = 0;
    if(i<0 || i==grid.size() || j<0 || j==grid[0].size() || grid[i][j]==0)return 0;

    fishes += grid[i][j];
    grid[i][j] = 0;

   fishes += (dfs(i,j+1,grid) + dfs(i+1,j,grid) + dfs(i-1,j,grid) + dfs(i,j-1,grid) ); 
   return fishes;
}

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(),ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0){
                    ans = max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};