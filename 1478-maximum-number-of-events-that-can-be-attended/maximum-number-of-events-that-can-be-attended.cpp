class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(begin(events),events.end());
        
        int currDay = events[0][0];
        int i=0,cnt=0;

        priority_queue<int,vector<int>,greater<>>pq;

        while(i<n || !pq.empty()){
            while(i<n && events[i][0]==currDay){
                pq.push(events[i++][1]);
            }

            if(!pq.empty()){
            pq.pop();
            cnt++;
            }

            currDay++;

            while(!pq.empty() && pq.top()<currDay)pq.pop();
        }
        return cnt;

    }
};