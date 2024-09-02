#define ll long long 
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll i(0);
        // ll k_n = k;
        ll sum =(accumulate(chalk.begin(),chalk.end(),0ll));
        k=k%sum; 
        if(k==0)return 0;
        // if(sum>k)return k;
        while(k!=0){
            ll curr = chalk[i];
            if(curr>k)return i;
            k -= curr;
            i=(i+1)%(chalk.size());
        }
        return i;
    }
};