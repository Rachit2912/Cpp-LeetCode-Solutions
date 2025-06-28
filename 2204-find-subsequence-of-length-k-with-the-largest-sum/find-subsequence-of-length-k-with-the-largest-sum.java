class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int n = nums.length;
        int [][]temp = new int[n][2];
        for(int i=0; i<n; i++){
            temp[i][0]=i;
            temp[i][1]=nums[i];
        }

        Arrays.sort(temp,(a,b)->Integer.compare(b[1],a[1]));
        Arrays.sort(temp,0,k,(a,b)->Integer.compare(a[0],b[0]));

        int []res = new int[k];
        for(int i=0; i<k; i++)res[i]=temp[i][1];
        return res;
    }
}