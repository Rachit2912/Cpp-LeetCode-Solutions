#define ll long long
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll fRow = accumulate(grid[0].begin(),grid[0].end(),0LL), sRow =0;

        ll blueGets= LONG_LONG_MAX;
        for(int i=0; i<grid[0].size(); i++){
            fRow -= grid[0][i];
            ll blueChooses = max(fRow,sRow);
            blueGets = min(blueGets,blueChooses);
            sRow += grid[1][i];
        }
        return blueGets;




    }
};