class Solution {
public:

    vector<int> parent;

    int find(int x){
        if(parent[x]==x)return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){parent[y] = x;}

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        parent.resize(n);
        vector<int>cost(n,-1);
        for(int i=0; i<n; i++){parent[i]=i;cost[i]=-1;}
        
        for(auto e : edges){
            int parent_u = find(e[0]), parent_v = find(e[1]);

            if(parent_u != parent_v){
                Union(parent_u,parent_v);
                cost[parent_u] &= cost[parent_v];
            }
            cost[parent_u] &= e[2];
        }


        vector<int> ans;
        for(auto &q : query){
            int parent_u = find(q[0]), parent_v = find(q[1]);
            
            if(q[0]==q[1]){
                ans.push_back(0);
            }else if(parent_u != parent_v){
                ans.push_back(-1);
            }else{
                ans.push_back(cost[parent_u]);
            }
        }
        return ans;
    }
};