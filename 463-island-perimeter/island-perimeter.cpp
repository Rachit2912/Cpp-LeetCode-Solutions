class Solution {
    void dfs(int x, int y, int r, int c, vector<vector<int>> &grid, int &perimeter){
        grid[x][y] = '$';
        int cellPerimeter = 4;

        // Check the four possible neighbors and decrease perimeter for shared boundaries
        if (x > 0 && grid[x-1][y] != 0) { // up
            cellPerimeter--;
            if (grid[x-1][y] == 1) dfs(x-1, y, r, c, grid, perimeter);
        }
        if (x < r-1 && grid[x+1][y] != 0) { // down
            cellPerimeter--;
            if (grid[x+1][y] == 1) dfs(x+1, y, r, c, grid, perimeter);
        }
        if (y > 0 && grid[x][y-1] != 0) { // left
            cellPerimeter--;
            if (grid[x][y-1] == 1) dfs(x, y-1, r, c, grid, perimeter);
        }
        if (y < c-1 && grid[x][y+1] != 0) { // right
            cellPerimeter--;
            if (grid[x][y+1] == 1) dfs(x, y+1, r, c, grid, perimeter);
        }

        perimeter += cellPerimeter;
    }
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int perimeter = 0;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, r, c, grid, perimeter);
                }
            }
        }
        
        return perimeter;
    }
};
