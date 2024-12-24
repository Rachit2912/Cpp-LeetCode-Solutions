class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};

        unordered_map<int,vector<int>>adj;
        vector<int> deg(n);


        for(auto &e : edges){
            deg[e[0]]++;deg[e[1]]++;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> res;
        queue<int> q; 
        for(int i=0; i<n; i++){
            if(deg[i] == 1)q.push(i);
        }

        while(n>2){
            int size = q.size();
            n-=size;
            while(size--){
                int front= q.front();
                q.pop();

                for(auto n:adj[front]){
                    deg[n]--;
                    if(deg[n]==1)q.push(n);
                }
            }
        }
        while(q.size()){res.push_back(q.front());q.pop();}
        return res;
    }

};