class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        int minCh1 = max(0,n-limit*2);
        int maxCh1 = min(n,limit);

        for(int ch1=minCh1; ch1<=maxCh1; ch1++){

            int N = n-ch1;

            int minCh2 = max(N-limit,0), maxCh2 = min(limit,N);

            ways += (maxCh2 - minCh2 + 1);
        }

        return ways;
    }
};