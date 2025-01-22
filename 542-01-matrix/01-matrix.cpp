class Solution {
public:
   
    bool isvalid(int i,int j,int m,int n)
    {
        if(i>=m||j>=n||j<0||i<0)
            return false;
        return true;
    }

    vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};


    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m =matrix.size(), n = matrix[0].size();
        queue<pair<int,int>> q; 
        vector<vector<int>> closestZero(m,vector<int>(n,-1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    q.push({i,j});
                    closestZero[i][j]=0;
                }
            }
        }


        while(!q.empty()){
            auto curr =q.front(); q.pop();
            for(auto& x : dir){
                int a = curr.first + x[0];
                int b = curr.second + x[1];
                if(isvalid(a,b,m,n) && closestZero[a][b]==-1){
                    q.push({a,b});
                    closestZero[a][b] = closestZero[curr.first][curr.second]+1;
                }
            }
        }
        return closestZero;
    }
};