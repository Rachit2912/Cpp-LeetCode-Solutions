class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0; long right = sqrt(c);

        while(left <= right){
            long sos = left*left + right*right;
            if(sos == c) return true;
            if(sos < c) left++ ;
            else right-- ;
        }
        return false;
    }
};