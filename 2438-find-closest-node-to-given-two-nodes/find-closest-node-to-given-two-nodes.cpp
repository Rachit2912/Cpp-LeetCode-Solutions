class Solution {

private:
    void bfs(int curr, vector<int> &edges, vector<int> &dist){
        int n = edges.size();
        queue<int> q; 
        q.push(curr);

        vector<bool> vis(n,false);
        dist[curr] = 0;

        while(!q.empty()){
            auto node = q.front();q.pop();

            if(vis[node])continue;

            vis[node]=true;
            auto n  = edges[node];
            if(n != -1 && !vis[n]){
                dist[n] = 1+dist[node];
                q.push(n);
            }
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n,INT_MAX), dist2(n,INT_MAX);

        bfs(node1,edges,dist1);
        bfs(node2,edges,dist2);

        int minDistNode = -1, minDist = INT_MAX;

        for(int node=0; node<n; node++){
            if(minDist > max(dist1[node],dist2[node])){
                minDist = max(dist1[node],dist2[node]);
                minDistNode = node;
            }
        }

        return minDistNode;
    }
};