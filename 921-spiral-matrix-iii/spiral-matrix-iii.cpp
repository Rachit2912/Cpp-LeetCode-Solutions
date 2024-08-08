class Solution {
public:

bool valid(int x, int y, int rows, int cols) {
    return (0<=x && x<rows)&&(0<=y && y<cols);

}
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        ans.push_back({rStart,cStart}); // first element pushed
        int sR = rStart-1;
        int eR = rStart+1;
        int sC = cStart-1;
        int eC = cStart+1;

         while(ans.size() < (rows * cols)) {

        // Move down along the right boundary (eC)
        for(int i = sR + 1; i <eR; i++) {
            if(valid(i, eC, rows, cols)) {
                ans.push_back({i, eC});
            }
        }
        eC++;  // Extend the right boundary to the right

        // Move left along the bottom boundary (eR)
        for(int j = eC - 1; j > sC; j--) {
            if(valid(eR, j, rows, cols)) {
                ans.push_back({eR, j});
            }
        }
        eR++;  // Extend the bottom boundary downwards

        // Move up along the left boundary (sC)
        for(int i = eR - 1; i > sR; i--) {
            if(valid(i, sC, rows, cols)) {
                ans.push_back({i, sC});
            }
        }
        sC--;  // Extend the left boundary to the left

        // Move right along the top boundary (sR)
        for(int j = sC + 1; j < eC; j++) {
            if(valid(sR, j, rows, cols)) {
                ans.push_back({sR, j});
            }
        }
        sR--;  // Extend the top boundary upwards
    }

    return ans;
    }
};