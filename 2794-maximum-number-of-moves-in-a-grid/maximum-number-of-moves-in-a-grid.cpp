class Solution {
public:
vector<int> dirns = {-1,0,1};
    int maxMoves(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();

        queue<vector<int>> q ;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0; i<m; i++){
            vis[i][0] = 1;
            q.push({i,0,0});
        }

        int maxMoves = 0;
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                vector<int> front = q.front();
                q.pop();

                int r = front[0], c = front[1], count = front[2];
                maxMoves = max(maxMoves,count);

                for(int d : dirns){
                    int nr = r+d,nc = c+1;
                    if(nr >= 0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[r][c] < grid[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr,nc,count+1});
                    }
                }
            }
        }
        return maxMoves;
    }
};