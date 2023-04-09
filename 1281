class Solution {
public:
    int subtractProductAndSum(int n) {
        int p=1,s=0;
        while(n) {
            s+=(n%10);
            p*=(n%10);
            n=n/10;
        }
       return (p-s);
    }
};
