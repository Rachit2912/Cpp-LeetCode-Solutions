class Solution {

        vector<pair<int,int>> directions =  {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


    private : 
    bool bfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int x, int y ){

        bool result = true;
        int m = grid2.size();
        int n = grid2[0].size();

        queue<pair<int,int>> q;
        q.push({x,y});
        grid2[x][y] = -1;


        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            if(grid1[x][y] != 1){
                result = false;
            }

            for(auto i :directions){
                int nx = x+i.first;
                int ny = y+i.second;

                if(nx>=0 && nx<m && ny>=0 && ny<n && grid2[nx][ny] ==1 ){
                    grid2[nx][ny] = -1;
                    q.push({nx,ny});
                }
            }
        }
        return result;
    }
public:

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        for(int i =0; i<grid2.size(); i++){
            for(int j =0; j<grid2[0].size();j++){
            if(grid2[i][j] == 1){count += bfs(grid1,grid2,i,j);}
        }
        }
        return count; 
    }
};