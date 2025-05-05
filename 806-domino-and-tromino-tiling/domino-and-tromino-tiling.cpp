class Solution {
public:
    const int M = 1e9+7;
    int numTilings(int n) {
        if(n<3)return n;
        vector<int> t(n+1,0);

        t[0]=1;
        t[1]=1;
        t[2]=2;
        // t[3]=5;

        for(int i=3; i<=n; i++){
            t[i] = (2*t[i-1] %M + t[i-3] %M) %M;
        }
        return t[n];
    }
};