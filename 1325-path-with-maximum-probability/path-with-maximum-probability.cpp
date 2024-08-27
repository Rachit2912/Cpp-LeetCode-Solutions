class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        double ans =0;

        vector<vector<pair<int, double>>> g(n);
        for(int i=0; i<edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});   
        }
        vector<int> seen(n, 0);

        priority_queue<pair<double,int>> q;
        q.push({1,start});  // prob,node

        vector<double> prob(n,0);
        prob[start] =1;

        while(!q.empty()){
            auto top = q.top();
            q.pop();
            seen[top.second]++ ;

            for(auto n : g[top.second]){
                if(prob[n.first] < n.second*(top.first)){
                    prob[n.first] = n.second*(top.first);
                    q.push({prob[n.first],n.first});
                }
            }
        }
        return prob[end];


    }
};