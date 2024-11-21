class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // create grid filled with 0 : 
        vector<vector<int>> mat(m,vector<int>(n,0));

        // mark walls with 2  and guards with 1 : 
        for(auto i : walls){mat[i[0]][i[1]] = 2;}
        for(auto i : guards){mat[i[0]][i[1]] = 1;}

        // go for each guard and mark its row and col until found any wall : 
        int gR = guards[0][0],gC = guards[0][1];
        for(auto i : guards){
            //left :
            gR = i[0];gC = i[1];gC--;
            while(gR>=0 && gR<m && gC>=0 && gC<n){
                if(mat[gR][gC] == 2 || mat[gR][gC] == 1){break;}
                mat[gR][gC]=-1;gC--;}
            //right :
            gR = i[0];gC = i[1];gC++;
            while(gR>=0 && gR<m && gC>=0 && gC<n){
                if(mat[gR][gC] == 2 || mat[gR][gC] == 1){break;}
                mat[gR][gC]=-1;gC++;}
            //up :
            gR = i[0];gC = i[1];gR--;
            while(gR>=0 && gR<m && gC>=0 && gC<n){
                if(mat[gR][gC] == 2 || mat[gR][gC] == 1){break;}
                mat[gR][gC]=-1;gR--;}
            //down :
            gR = i[0];gC = i[1];gR++;
            while(gR>=0 && gR<m && gC>=0 && gC<n){
                if(mat[gR][gC] == 2 || mat[gR][gC] == 1){break;}
                mat[gR][gC]=-1;gR++;}
            
        }

        int ans =0;
        for(auto &i : mat){
            for(auto &j : i){
                if(j==0)ans++;
            }
        }
        return ans;
    }
};