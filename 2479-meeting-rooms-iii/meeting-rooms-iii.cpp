using P = pair<long long,int>;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(begin(meetings),end(meetings));
        vector<int> cnt(n,0);
        priority_queue<P,vector<P>,greater<P>>used;
        priority_queue<int,vector<int>,greater<>>unused;
        for(int i=0; i<n; ++i)unused.push(i);

        for(auto m : meetings){

            while(!used.empty() && used.top().first <= m[0]){
                int r = used.top().second;
                used.pop();
                unused.push(r);
            }

            if(!unused.empty()){
                int r = unused.top();unused.pop();
                used.push({m[1],r});
                cnt[r]++;
            }else{
                int r = used.top().second;
                long long endTime = used.top().first;
                used.pop();
                used.push({endTime+(m[1]-m[0]),r});
                cnt[r]++;
            }
        }
        for(int r=0; r<n; ++r)if(cnt[r] == *max_element(cnt.begin(),end(cnt)))return r;
        return -1;
    }
};