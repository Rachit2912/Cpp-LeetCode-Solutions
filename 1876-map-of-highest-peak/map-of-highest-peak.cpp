class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> heights(isWater.size(),vector<int>(isWater[0].size(),-1));
        queue<pair<int,int>> cell;
        for(int i=0; i<isWater.size(); i++){
            for(int j=0; j<isWater[0].size(); j++){
                if(isWater[i][j]==1){
                    cell.push({i,j});
                    heights[i][j]=0;
                    }
            }
        }

        while(!cell.empty()){
            auto p = cell.front();cell.pop();
            int r = p.first, c = p.second;

            if(c+1<isWater[0].size()){
                if(heights[r][c+1]==-1){
                    heights[r][c+1]=heights[r][c]+1;cell.push({r,c+1});
                }
            }


            if(c-1>=0){
                if(heights[r][c-1]==-1){
                    heights[r][c-1]=heights[r][c]+1;cell.push({r,c-1});
                }
            }


            if(r+1<isWater.size()){
                if(heights[r+1][c]==-1){
                    heights[r+1][c]=heights[r][c]+1;cell.push({r+1,c});
                }
            }


            if(r-1>=0){
                if(heights[r-1][c]==-1){
                    heights[r-1][c]=heights[r][c]+1;cell.push({r-1,c});
                }
            }


        }

        return heights;
    }
};