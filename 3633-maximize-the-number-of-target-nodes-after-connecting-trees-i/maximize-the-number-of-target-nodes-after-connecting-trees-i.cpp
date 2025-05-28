class Solution {
private:
    int dfs(int curr, int parent, vector<vector<int>> &adj, int k){
        if(k<0)return 0;

        int cnt = 1;
        for(auto n : adj[curr]){
            if(n == parent)continue;

            cnt += dfs(n,curr,adj,k-1);
        }

        return cnt;
    }


    vector<int> countTargets(vector<vector<int>> &edges, int k){
        int n = edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int>countTarget(n);

        for(int i=0; i<n; i++){
            countTarget[i] = dfs(i,-1,adj,k);
        }
        return countTarget;
    }
public:

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n1 = edges1.size()+1, n2 = edges2.size()+1;
        vector<int> target1 = countTargets(edges1,k);
        vector<int> target2 = countTargets(edges2,k-1);

        int maxTargetsFrom2 = *max_element(target2.begin(),end(target2));
        vector<int> ans(n1);
        for(int i=0; i<n1; i++){
            ans[i] = target1[i] + maxTargetsFrom2;
        }
        return ans;
    }
};