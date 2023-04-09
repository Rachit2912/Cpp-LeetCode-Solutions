class Solution {
public:
    int subtractProductAndSum(int n) {
        int d=0,p=1,s=0;
        while(n>0) {
            d=n%10;
            s+=d;
            p*=d;
            n=n/10;
        }
       return (p-s);
    }
};
