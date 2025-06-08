class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int curr=1; curr<10; curr++)solve(curr,n,ans);
        return ans;
    }

private:
    void solve(int curr, int n, vector<int> &ans){
        if(curr>n)return;

        ans.push_back(curr);

        for(int d=0; d<10; d++){
            int nextNo = curr*10+d;
            if(nextNo>n)break;
            else solve(nextNo,n,ans);
        }
    }
};