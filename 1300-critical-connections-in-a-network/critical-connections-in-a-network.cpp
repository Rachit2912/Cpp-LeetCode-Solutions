class Solution {
public:

void dfs(int node, int &parent, int &timer, vector<int> &disc, vector<int> &low,
         vector<vector<int>> &result, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &vis){

            vis[node] = true;
            disc[node] = low[node] = timer++ ;

            for(auto n :adj[node]){
                if(n==parent) continue;

                if(!vis[n]){
                    dfs(n,node,timer,disc,low,result,adj,vis);
                    low[node] = min(low[node],low[n]);

                if(low[n] > disc[node]){
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(n);
                    result.push_back(temp);
                }
                }

                else{
                    low[node] = min(low[node],disc[n]);
                }
            }

         }



    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        // create adjlist : 
        unordered_map<int,list<int>> adj;
        for(int i =0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        int timer = 0;
        vector<int> disc(n,-1);
        vector<int> low(n,-1);
        int parent  = -1;
        unordered_map<int,bool> vis;
        for(int i =0;i<n;i++){vis[i] = false;}
        vector<vector<int>> result;

        for(int i =0;i<n;i++){
            if(!vis[i]){
                dfs(i,parent,timer,disc,low,result,adj,vis);
            }
        }

        return result;
    }
};