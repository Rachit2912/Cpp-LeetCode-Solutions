class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degrees(n,0);
        for(auto i : roads){
            degrees[i[0]]++ ;
            degrees[i[1]]++ ;
        }

        sort(degrees.begin(),degrees.end());

        long long val = 1;
        long long totalImp = 0;
        for(long long d : degrees){
            totalImp += (val*d) ;
            val++ ;
        }

        return totalImp;


    }
};