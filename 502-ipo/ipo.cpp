class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> projects(profits.size());
        for(int i= 0; i<profits.size(); i++){
            projects[i] = {capital[i],profits[i]};
        }
        int i =0;
        sort(projects.begin(),projects.end());
        priority_queue<int> maxProfit;
        while(k--){
            while(i < profits.size() && projects[i].first <= w){
                maxProfit.push(projects[i].second);
                i++ ; 
            }

            if(maxProfit.empty()) break;

            w += maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};