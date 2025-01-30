class Solution {
    private:
    bool isBiPartite(unordered_map<int,vector<int>> &adj, int curr, vector<int> &color, int currColor){
        
        color[curr] = currColor;

        for(int n : adj[curr]){
            if(color[n] == currColor)return false;

            if(color[n] == -1){
                if(isBiPartite(adj,n,color,1-currColor) == false)return false;
            }
        }
        return true;
    }

    int bfs(unordered_map<int,vector<int>> &adj, int curr, int n ){
        vector<bool> vis(n,false);
        queue<int> q; 
        vis[curr] = true; 
        q.push(curr);

        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int top = q.front();q.pop();
                for(int n : adj[top]){
                    if(!vis[n]){
                        q.push(n);
                        vis[n] = true;
                    }
                }
            }
            level++ ; 
        }
        return level;
    }

    int getMaxOfComponent(unordered_map<int,vector<int>> &adj,int curr,vector<bool> &vis,vector<int> &maxLevels){
        int maxGrp = maxLevels[curr];
        vis[curr] = true;

        for(int &n : adj[curr]){
            if(!vis[n]){
                maxGrp = max(maxGrp,getMaxOfComponent(adj,n,vis,maxLevels));
            }
        }
        return maxGrp;
    }


public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        
        // creating the adj list : 
        unordered_map<int,vector<int>> adj;
        for(auto e : edges){
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }

        // bipartite check : 
        vector<int>color(n,-1);
        for(int node=0; node<n; node++){
            if(color[node]==-1){
                if(isBiPartite(adj,node,color,1)==false)return -1;
            }
        }

        // bfs level finding for max. levels for each node : 
        vector<int> maxLevels(n,0);
        for(int i=0; i<n; i++){
            maxLevels[i] = bfs(adj,i,n);
        }

        // max grp for each component : 
        vector<bool> vis(n,false);
        int maxOfEachComponent = 0;
        for(int node=0; node<n; node++){
            if(!vis[node]){
                maxOfEachComponent += getMaxOfComponent(adj,node,vis,maxLevels);
            }
        }
        return maxOfEachComponent;
    }
};