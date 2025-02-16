class Solution {
private : 
bool solve(int idx, int n, vector<bool>& settled, vector<int>& ans){
    if(idx >= ans.size())return true;

    if(ans[idx] != -1)return solve(idx+1,n,settled,ans);

    for(int no=n; no>0; no--){
        if(settled[no])continue;

        // try:
        settled[no]=true;
        ans[idx]=no;

        // checking : 
        if(no==1 && solve(idx+1,n,settled,ans))return true;

        else{
            int j = ans[idx]+idx;

            if(j<ans.size() && ans[j] == -1){
                ans[j]=no;
                if(solve(idx+1,n,settled,ans))return true;
                ans[j]=-1;
            }
        }
        //backtrack:
        settled[no] = false;
        ans[idx]=-1;
    }
    return false;
}
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1,-1);
        vector<bool> settled(n+1,false);

        int idx=0;
        solve(idx,n,settled,ans);
        return ans;
    }
};