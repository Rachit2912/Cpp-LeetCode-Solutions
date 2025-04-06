class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();int i=0;
        int prim_diag = accumulate(mat.begin(),mat.end(),0,
        [&i](int acc, const vector<int> &row){
            return acc + row[i++];
        });
        
        i=0;
        int sec_diag = accumulate(mat.begin(),mat.end(),0,
        [&i,n](int acc, const vector<int> &row){
            return acc + row[n-1-(i++)];
        });

        int total = prim_diag + sec_diag;

        if (n % 2 == 1) {
            total -= mat[n / 2][n / 2];
        }

        return total;
    }
};