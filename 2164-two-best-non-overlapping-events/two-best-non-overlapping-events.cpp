class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(begin(events),end(events));
        vector<vector<int>> dp(events.size(),vector<int>(3,-1));
        return solve(events,0,0,dp);
    }

    int solve(vector<vector<int>> &events, int idx, int cnt, vector<vector<int>> &dp){

        if(cnt==2 || idx>=events.size()) return 0;

        if(dp[idx][cnt]==-1){

            int currEventEnding = events[idx][1];
            int nextEventIdx = idx+1, nextEventIdxEnd = events.size()-1;

            while(nextEventIdx < nextEventIdxEnd){
                int mid = nextEventIdx + ((nextEventIdxEnd-nextEventIdx)/2);
                if(events[mid][0] > currEventEnding)nextEventIdxEnd = mid;
                else nextEventIdx =mid+1;
            }   

        int include = events[idx][2] + ((nextEventIdx < events.size() && events[nextEventIdx][0] > currEventEnding) ? solve(events,nextEventIdx,cnt+1,dp) : 0);
        int exclude = solve(events, idx+1, cnt, dp);
        dp[idx][cnt] = max(include,exclude);
        }
        return dp[idx][cnt];
    }

};