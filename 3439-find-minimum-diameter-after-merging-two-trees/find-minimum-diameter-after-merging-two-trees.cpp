class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int,vector<int>> adj2 = buildAdj(edges2);

        int d1 = diameter(adj1),d2 = diameter(adj2), merged_diameter = ceil(d1/2.0) + ceil(d2/2.0) + 1;

        return max({d1,d2,merged_diameter});
    }

private : 
unordered_map<int,vector<int>> buildAdj(vector<vector<int>> edges){
    unordered_map<int,vector<int>> adj;
    for(auto e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
        return adj;
}

int diameter(unordered_map<int,vector<int>> adj){
    int n = adj.size()+1;
    auto [farthestNode,distance] = findFarthestNode(n,adj,0);
    auto [secondFarthestNode,diameter] = findFarthestNode(n,adj,farthestNode);
    return diameter;
}

pair<int,int> findFarthestNode(int n, unordered_map<int,vector<int>> adj, int srcNode){
    queue<int> q; 
    vector<bool>vis(n,false);
    q.push(srcNode);
    vis[srcNode]=true;

    int maxDistance = 0, farthestNode= srcNode;

    while(!q.empty()){
        int size = q.size();
        while(size--){
            int front = q.front();q.pop();
            farthestNode = front;

            for(auto n : adj[front]){
                if(!vis[n]){
                    vis[n] = true;
                    q.push(n);
                }
            }
        }
            if(!q.empty())maxDistance++;
    }
    return {farthestNode,maxDistance};
}
};