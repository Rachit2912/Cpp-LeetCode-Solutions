class Solution {
public:

void findChildren(int node, unordered_map<int,list<int>> &adj, vector<bool> &visited){
    visited[node] = true;

    for(int n : adj[node]){
        if(!visited[n]) findChildren(n,adj,visited);
    }

}


    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        for(auto edge: edges){
            adj[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> ancestors;

        for(int i =0;i<n;i++){
            vector<int> anc; 
            vector<bool> visited(n,false);
            findChildren(i,adj,visited);

            for(int j = 0;j<n;j++){
                if(j == i) continue;
                if(visited[j]){anc.push_back(j);}
            }
            ancestors.push_back(anc);
        }
        return ancestors;
    }
};