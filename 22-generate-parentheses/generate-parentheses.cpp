class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr="";
        int open=0,close=0;
        solve(curr,n,ans,open,close);
        return ans;
    }

private:
    void solve(string curr, int n, vector<string> &ans, int open, int close){

        // base case :
        if(curr.length()==2*n){
            ans.push_back(curr);
            return;
        }

        // explore with safety + traceback :
        if(open<n){
            curr.push_back('(');
            solve(curr,n,ans,open+1,close);
            curr.pop_back();
        }

        if(close<open){
            curr.push_back(')');
            solve(curr,n,ans,open,close+1);
            curr.pop_back();
        }
    }
};