class Solution {
    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.length;
        int[] freeTime = new int[n+1];
        freeTime[0] = startTime[0];
        int ans = freeTime[0];
        for(int i=1; i<n; ++i){
            freeTime[i] = startTime[i]-endTime[i-1];
            ans = Math.max(ans,freeTime[i]);
        }
        freeTime[n] = eventTime - endTime[n-1];
        ans = Math.max(ans,freeTime[n]);

        n = freeTime.length;
        int[] maxLeftFreeTime = new int[n];
        int[] maxRightFreeTime = new int[n];
        maxLeftFreeTime[0] = 0;
        for(int i=1; i<n; ++i)maxLeftFreeTime[i] = Math.max(maxLeftFreeTime[i-1],freeTime[i-1]);
        maxRightFreeTime[n-1] = 0;
        for(int i=n-2; i>-1; --i)maxRightFreeTime[i] = Math.max(maxRightFreeTime[i+1],freeTime[i+1]);

        for(int i=1; i<n; ++i){
            int currEvntTime = endTime[i-1]-startTime[i-1];

            // case 1 : move somewhere else : 
            if(currEvntTime <= Math.max(maxLeftFreeTime[i-1],maxRightFreeTime[i])){
                ans = Math.max(ans,freeTime[i-1]+currEvntTime+freeTime[i]);
            }
            // case 2 : shift to adjacent : 
            ans = Math.max(ans,freeTime[i-1]+freeTime[i]);
        }
        return ans;
    }
}