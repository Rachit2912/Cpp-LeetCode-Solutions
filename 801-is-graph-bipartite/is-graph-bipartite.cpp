class Solution {
    private : 
    bool dfs(vector<vector<int>> &adj, int curr, vector<int> &color, int currColor){
        color[curr] = currColor;

        for(auto &n : adj[curr]){
            if(color[n] == currColor)return false;

            if(color[n] == -1){
                // color[n] = 1-currColor;
                if(dfs(adj,n,color,1-currColor)==false)return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // coloring the graph in 2 parts : 0 - red and 1 - blue 
        vector<int> color(graph.size(),-1);
        int currColor = 1;  // starting with blue 

        for(int i=0; i<graph.size(); i++){
            if(color[i] == -1){
            if(dfs(graph,i,color,currColor) == false)return false;
            }
        }
        return true;
    }
};