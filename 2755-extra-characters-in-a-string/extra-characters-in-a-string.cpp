class Solution {
public:
int dp[51];
int solve(int idx, string s, unordered_set<string> &dict, int n){
    // base case : 
    if(idx >= n)return 0;

    // if it's already saved in memset : 
    if(dp[idx] != -1)return dp[idx];

    // ya to curr idx wale ko extra char le :
    int result = 1 + solve(idx+1,s,dict,n);
    // ya naa le : agr naa le to substring bnake dhundho wha se 
    for(auto j=idx; j<n; j++){
        string curr = s.substr(idx,j-(idx-1));
        // check if this substr is there in dict or not :
        if(dict.count(curr)){
            // valid substring : 
            result = min(result,solve(j+1,s,dict,n));
        }

    }
    
    return dp[idx] = result;
}
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> dict(dictionary.begin(),dictionary.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,s,dict,n);
    }
};