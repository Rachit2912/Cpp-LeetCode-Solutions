typedef long long ll;
vector<int> pred;
vector<ll>dp;

class Solution {
public:

    ll dfs(int mask,vector<int>& score, int n){
        if(mask == (1<<n)-1)return 0;
        if(dp[mask]!=-1)return dp[mask];

        int pos = __builtin_popcount(mask)+1;
        ll best = LLONG_MIN;

        for(int v=0; v<n; v++){
            if(mask & (1<<v))continue;

            if((pred[v] & ~mask) == 0){
                ll cand = dfs(mask | (1<<v),score,n);
                // if(cand!=LLONG_MIN)
                best = max(best,cand+1LL*score[v]*pos);
            }
        }
        return dp[mask] = (best==LLONG_MIN) ? 0 : best;
    }

    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        pred.assign(n,0);
        for(auto &e : edges) pred[e[1]] |= (1<<e[0]);
        dp.assign(1<<n,-1);
        return dfs(0,score,n);
    }
};