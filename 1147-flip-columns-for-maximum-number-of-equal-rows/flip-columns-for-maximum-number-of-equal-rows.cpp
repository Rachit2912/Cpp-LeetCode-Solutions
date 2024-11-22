class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxR = 0;
        for(auto& currR : matrix){

            // find the inverted : 
            vector<int> inverted(n);
            for(int col=0; col<n; col++){
                inverted[col] = !currR[col];
            }

            // find the rows exactly as the currR or its inverted row :
            int count = 0;
            for(auto& row : matrix){
                if(row == currR || row == inverted)count++;
            }
            maxR = max(maxR,count);
        }
        return maxR;
    }
};