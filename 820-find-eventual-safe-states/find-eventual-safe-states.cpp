class Solution {
public:
bool dfs(int node, vector<bool> &vis, vector<vector<int>> &graph, vector<bool> &inStack){
    
    vis[node] = true;
    inStack[node] = true;

    for(auto n: graph[node]){
        if(!vis[n] && dfs(n,vis,graph,inStack)){
            return true;
        }
        else if(inStack[n])return true;
    }
    inStack[node] = false;
    return false;
}

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n,false), inStack(n,false);
        for(int i=0; i<n; i++){
            if(!vis[i])dfs(i,vis,graph,inStack);
        }

        vector<int> safeNodes;
        for(int i=0; i<n; i++){
            if(!inStack[i])safeNodes.push_back(i);
        }
        return safeNodes;
    }
};