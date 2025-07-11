class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long>endTime(n,0),cnt(n,0);
        sort(begin(meetings), end(meetings)); 

        for(int i=0; i<meetings.size(); ++i){

            int j=0;
            bool found=false;
            long long EarliestEnd = LLONG_MAX;
            int EarliestRoom = 0;
            while(j<n){
                if(endTime[j] <= meetings[i][0]){
                    endTime[j] = meetings[i][1];
                    cnt[j]++;
                    found=true;
                    break;
                }

                if(endTime[j]<EarliestEnd){
                    EarliestEnd = endTime[j];
                    EarliestRoom = j;
                }
                j++;
            }
            
            if(found==false){
                endTime[EarliestRoom] += (meetings[i][1]-meetings[i][0]);
                cnt[EarliestRoom]++;
            }


        }
        for(int r=0; r<n; ++r)if(cnt[r]==*max_element(cnt.begin(),end(cnt)))return r;
        return -1;
    }
};