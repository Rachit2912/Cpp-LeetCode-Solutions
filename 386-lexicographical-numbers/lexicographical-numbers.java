class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> ans = new ArrayList<>();
        for(int curr=1; curr<10; curr++)solve(curr,ans,n);
        return ans;
    }

    private void solve(int curr, List<Integer> ans, int n){
        if(curr>n)return;

        ans.add(curr);

        for(int d=0; d<10; d++){
            int nextNo = curr*10+d;
            if(nextNo>n)break;
            else solve(nextNo,ans,n);
        }
    }
}