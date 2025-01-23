class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rCnts(size(grid[0]),0), cCnts(size(grid),0);
        for(int r=0; r<size(grid); ++r){
            for(int c=0; c<size(grid[0]); ++c){
                if(grid[r][c]){rCnts[c]++ ; cCnts[r]++ ;}
            }
        }

        int ans(0);
        for(int r=0; r<size(grid); r++){
            for(int c=0; c<size(grid[0]); ++c){
                if(grid[r][c]){
                    ans += (rCnts[c]>1 || cCnts[r]>1);
                }
            }
        }
        return ans;
    }
};