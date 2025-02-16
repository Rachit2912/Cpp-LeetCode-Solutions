class Solution {
public:
    vector<vector<int>> dirs = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    vector<vector<int>> grid;
    int m, n;

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        this->grid = grid;

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, 1);
                    res = max(res, dfs(i, j, 0, 2, false));
                    res = max(res, dfs(i, j, 1, 2, false));
                    res = max(res, dfs(i, j, 2, 2, false));
                    res = max(res, dfs(i, j, 3, 2, false));
                }
            }
        }
        return res;
    }

    int dfs(int i, int j, int dir, int target, bool turned) {
        int x = i + dirs[dir][0], y = j + dirs[dir][1];

        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != target) {
            return 1;
        }

        int straight = 1 + dfs(x, y, dir, target == 2 ? 0 : 2, turned);
        int turn = 0;
        if (!turned) {
            turn = 1 + dfs(x, y, (dir + 1) % 4, target == 2 ? 0 : 2, true);
        }

        return max(straight, turn);
    }
};
