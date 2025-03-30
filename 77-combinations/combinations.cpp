class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>temp;
        solve(1,temp,ans,n,k);
        return ans;
    }

private:
    void solve(int start, vector<int> &temp, vector<vector<int>> &ans, int n, int k){
        if(k==0){ans.push_back(temp);return;}
        if(start>n)return;

        temp.push_back(start);
        solve(start+1,temp,ans,n,k-1);
        temp.pop_back();
        solve(start+1,temp,ans,n,k);
    }
};