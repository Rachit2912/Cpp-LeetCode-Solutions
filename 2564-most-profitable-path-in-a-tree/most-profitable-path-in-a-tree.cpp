class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> bobMap;
    int aliceIncome;

    bool dfsBob(int curr, int t, vector<bool> &vis){
        vis[curr] = true;
        bobMap[curr] = t;

        if(curr==0)return true;

        for(auto n : adj[curr]){
            if(!vis[n]){
                if(dfsBob(n,t+1,vis))return true;
            }
        }
        bobMap.erase(curr);
        return false;
    }

    void dfsAlice(int curr, int t, int income, vector<bool> &vis, vector<int> &amount){
        vis[curr]=true;

        if(bobMap.find(curr)==bobMap.end() || t<bobMap[curr]){
            income += amount[curr];
        } else if(t==bobMap[curr]){
            income += (amount[curr]/2);
        }

        if(adj[curr].size() == 1 && curr!=0){
            aliceIncome = max(aliceIncome,income);
        }

        for(auto n : adj[curr]){
            if(!vis[n]){
                dfsAlice(n,t+1,income,vis,amount);
            }
        }        
    }


    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        aliceIncome = INT_MIN;

        for(auto e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int t = 0;
        vector<bool>vis(n,false);
        dfsBob(bob,t,vis);

        int income =0;
        vis.assign(n,false);
        dfsAlice(0,0,income,vis,amount);

        return aliceIncome;
    }
};