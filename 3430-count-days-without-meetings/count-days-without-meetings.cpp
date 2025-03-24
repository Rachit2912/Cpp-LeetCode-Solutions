class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
         sort(meetings.begin(),meetings.end());
        int ans=0, s=0, e=0;

        for(auto &m : meetings){
            if(m[0]>e)ans += m[0]-e-1;

            e = max(e,m[1]);
        }

        if(days>e)ans += days-e;
        return ans;
    }
};