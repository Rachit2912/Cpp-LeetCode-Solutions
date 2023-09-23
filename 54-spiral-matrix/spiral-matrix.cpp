class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> a;

        int count = 0 ;
        int total = r*c ;

        int sR=0,sC=0,eR=r-1,eC=c-1;


        while(count<total){
            for(int i=sC; i<=eC && count<total; i++){
                a.push_back(matrix[sR][i]);
                count++ ;
            }
            sR++ ; 

            for(int i=sR; i<=eR && count<total; i++){
                a.push_back(matrix[i][eC]);
                count++ ;
            }
            eC-- ;

            for(int i=eC; i>=sC && count<total; i--){
                a.push_back(matrix[eR][i]);
                count++ ;
            }
            eR-- ;

            for(int i=eR; i>=sR && count<total; i--){
                a.push_back(matrix[i][sC]);
                count++ ;
            }
            sC++ ;

        }


return a;
    }
};