class Solution {
    private : 
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>> &grid2, int x, int y){

        int m = grid2.size();
        int n = grid2[0].size();

        if(x<0 || x>=m || y<0 || y>=n) return 1;
        if(grid2[x][y] != 1) return 1;

        grid2[x][y] = -1;

        bool result = (grid1[x][y] ==1);
        result = result & dfs(grid1,grid2,x+1,y) & dfs(grid1,grid2,x-1,y) & dfs(grid1,grid2,x,y+1) & dfs(grid1,grid2,x,y-1);

        return result;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        int count = 0;

        for(int i =0; i<m;i++){
            for(int j =0; j<n; j++){
                if(grid2[i][j] == 1){
                    count+= dfs(grid1,grid2,i,j);
                }
            }
        }
        return count;
    }
};