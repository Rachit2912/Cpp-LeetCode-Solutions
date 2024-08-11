class Solution {
public:

void dfs(int x, int y, int r, int c, vector<vector<char>> &grid){
    grid[x][y] = '$';

    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    for(auto i : dir){
        int x_ = x+i.first;
        int y_ = y+i.second;

        if((x_ >= 0) && (x_ < r) && (y_ >= 0) && (y_ < c) && (grid[x_][y_] == '1')) {dfs(x_,y_,r,c,grid); }
    }
}

    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        int m = grid.size(),n= grid[0].size();
        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == '1') 
                {dfs(i,j,m,n,grid);
                count++ ; 
                }
            }
        }
        return count;
    }
};