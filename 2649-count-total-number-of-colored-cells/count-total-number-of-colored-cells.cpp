class Solution {
public:
    long long coloredCells(int n) {
        long long start = 1; 
        long long i =0;
        while(n--){
            start += (4*i);
            i++;
        }
        return start;
    }
};