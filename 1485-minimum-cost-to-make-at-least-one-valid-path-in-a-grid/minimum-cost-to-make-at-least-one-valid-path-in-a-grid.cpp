class Solution {
public:
vector<vector<int>> dir ={{0,1},{0,-1},{1,0},{-1,0}};

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        pq.push({0,0,0});
        vector<vector<int>> res(m,vector<int>(n,INT_MAX));
        res[0][0] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int currCost = curr[0], i = curr[1], j = curr[2];

            for(int d=0; d<4; d++){
                int newI = i+dir[d][0], newJ = j+dir[d][1];

                if(newI>=0 && newI<m && newJ>=0 && newJ<n){
                    int newCost = currCost + ( ( (grid[i][j]-1) != d) ?  1 : 0);

                    if(newCost < res[newI][newJ]){
                        res[newI][newJ] = newCost;
                        pq.push({newCost,newI,newJ});
                    }

                }
            }

        }
        return res[m-1][n-1];
    }

};