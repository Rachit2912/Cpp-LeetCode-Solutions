class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        // prev i.e 0th row ko bhrdo : 
        vector<long long> prev(n);
        for(int i =0; i<n; i++) prev[i] = points[0][i];

        // row wise check kro : 
        for(int i =1; i<m; i++){
            vector<long long>left(n,0);
            vector<long long> right(n,0);

            // left ka setup :
            left[0] = prev[0];
            for(int j =1; j<n; j++) left[j] = max(prev[j],left[j-1]-1);

            // right ka setup : 
            right[n-1] = prev[n-1];
            for(int j = n-2; j>=0; j--) right[j] = max(prev[j],right[j+1]-1);

            // current ka setup : 
            vector<long long> curr(n);
            for(int j = 0; j<n; j++){
                curr[j] = points[i][j] + max(left[j],right[j]);
            }

            prev = curr;
        }
        return *max_element(prev.begin(),prev.end());
    }
};