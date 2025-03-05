class Solution {
public:
    long long coloredCells(int n) {
       //2n-1
       long long  start = 1, odd =1;
       while(n--){
        start += odd;
        odd+=2;
       }
       return 2*start-odd;
    }
};