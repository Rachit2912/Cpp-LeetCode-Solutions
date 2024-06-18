class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < profit.size(); i++){
            pq.push({profit[i],difficulty[i]});
        }

        sort(worker.begin(),worker.end(),greater<int>());

        int i = 0 ;
        int maxProfit  = 0;
        while(i < worker.size() && !pq.empty()){
            if(worker[i] < pq.top().second) pq.pop();
            else {
                maxProfit += pq.top().first ; 
                i++ ;
            }
        }
        return maxProfit;

    }
};