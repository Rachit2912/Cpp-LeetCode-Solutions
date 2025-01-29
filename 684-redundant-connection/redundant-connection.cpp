class Solution {
public:

bool dfs(unordered_map<int,vector<int>> &adj, vector<bool> &vis, int curr, int goal){
    vis[curr] = true;

    if(curr == goal)return true;

    for(int n : adj[curr]){
        if(vis[n])continue;

        if(dfs(adj,vis,n,goal))return true;
    }
    return false;
}

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<n; i++){
            int u = edges[i][0], v = edges[i][1];

            vector<bool>vis(n+1,false);
            if(adj.find(u) != adj.end() && adj.find(v) != adj.end() && dfs(adj,vis,u,v)){
                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        return {};
    }
};