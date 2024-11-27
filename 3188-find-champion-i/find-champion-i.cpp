class Solution {
public:
    int findChampion(vector<vector<int>>& v) {
            int w=-1;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1){if(w==j || w==-1)w=i;}
            }
            // if(c==n-1)
            //     return i;
        }
        return w;
    }
};