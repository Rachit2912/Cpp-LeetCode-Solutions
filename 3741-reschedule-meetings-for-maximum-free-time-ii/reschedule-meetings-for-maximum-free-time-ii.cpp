class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);
        for(int i=1; i<startTime.size(); ++i)freeTime.push_back(startTime[i]-endTime[i-1]);
        freeTime.push_back(eventTime-endTime[endTime.size()-1]);

        int n = freeTime.size();
        vector<int> maxLeftFreeTime(n,0), maxRightFreeTime(n,0);
        for(int i=1; i<n; ++i)maxLeftFreeTime[i] = max(maxLeftFreeTime[i-1],freeTime[i-1]);
        for(int i=n-2; i>-1; --i)maxRightFreeTime[i] = max(maxRightFreeTime[i+1],freeTime[i+1]);

        int ans = *max_element(freeTime.begin(),end(freeTime));
        for(int i=1; i<n; ++i){
            int currEvntTime = endTime[i-1]-startTime[i-1];

            // case 1 : moving somewhere else :
            if(currEvntTime <= max(maxLeftFreeTime[i-1],maxRightFreeTime[i])){
                ans = max(ans,freeTime[i-1]+currEvntTime+freeTime[i]);
            } 
            // case 2 : just shift adjacently :
            ans = max(ans,freeTime[i-1]+freeTime[i]);
        }

        return ans;
    }
};