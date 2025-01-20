class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<int> rCnt(rows), cCnt(cols);
        unordered_map<int,pair<int,int>> numToPos; 

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                numToPos[mat[r][c]] = {r,c};
            }
        }

        for(int i=0; i<arr.size(); i++){
            int no = arr[i];
            auto [row,col] = numToPos[no];
            rCnt[row]++ ; cCnt[col]++ ; 

            if(rCnt[row]==cols || cCnt[col]==rows)return i;
        }
        return -1;
    }
};