class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        int n = startTime.length;
        int[] freeTime = new int[n+1];
        freeTime[0]=startTime[0];
        for(int i=1; i<n; ++i)freeTime[i] = startTime[i]-endTime[i-1];
        freeTime[n] = eventTime-endTime[n-1];

        int l=0,currSum=0,maxSum=0;
        for(int r=0; r<freeTime.length; ++r){
            currSum += freeTime[r];
            if(r-l+1 > k+1){
                currSum -= freeTime[l];
                l++;
            }
            maxSum = Math.max(maxSum,currSum);
        }
        return maxSum;
    }
}