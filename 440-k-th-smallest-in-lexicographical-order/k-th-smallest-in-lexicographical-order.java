class Solution {
    private int PrefixCount(long curr, long next, int n){
        int cnt =0;
        while(curr <= n){
            cnt += (next-curr);
            curr*=10;
            next*=10;
            next = Math.min(next,n+1);
        }
        return cnt;
    }
    public int findKthNumber(int n, int k) {
        int curr=1;k--;
        while(k>0){
            int cnt = PrefixCount(curr,curr+1,n);
            if(cnt<=k){
                k-=cnt;curr++;
            }else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
}