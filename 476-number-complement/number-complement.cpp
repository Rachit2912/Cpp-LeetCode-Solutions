class Solution {
public:
    int findComplement(int num) {
        int no = num;
        int mask = ~0;
        while(num != 0){
            num >>= 1;
            mask <<= 1;
        }
        return (~no & ~mask);
        
    }
};