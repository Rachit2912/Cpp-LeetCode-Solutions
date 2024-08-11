class Solution {
    void dfs(int x, int y, int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &visited, int &perimeter){
        visited[x][y] = true;
        int cellPerimeter = 4;

        // Check the four possible neighbors and decrease perimeter for shared boundaries
        if (x > 0 && grid[x-1][y] == 1) { // up
            cellPerimeter--;
            if (!visited[x-1][y]) dfs(x-1, y, r, c, grid, visited, perimeter);
        }
        if (x < r-1 && grid[x+1][y] == 1) { // down
            cellPerimeter--;
            if (!visited[x+1][y]) dfs(x+1, y, r, c, grid, visited, perimeter);
        }
        if (y > 0 && grid[x][y-1] == 1) { // left
            cellPerimeter--;
            if (!visited[x][y-1]) dfs(x, y-1, r, c, grid, visited, perimeter);
        }
        if (y < c-1 && grid[x][y+1] == 1) { // right
            cellPerimeter--;
            if (!visited[x][y+1]) dfs(x, y+1, r, c, grid, visited, perimeter);
        }

        perimeter += cellPerimeter;
    }
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int perimeter = 0;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    dfs(i, j, r, c, grid, visited, perimeter);
                }
            }
        }
        
        return perimeter;
    }
};
