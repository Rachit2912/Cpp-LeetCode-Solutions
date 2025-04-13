#define ll long long 
class Solution {
public:
const int mod = 1e9+7;


    string convert(const string &dStr, int base){
        if(dStr=="0")return "0";
        string result,current=dStr;
        while(current!="0"){
            string nextQuotient;
            nextQuotient.reserve(current.size());
            ll rem = 0;
            for(char c : current){
                int digit = c-'0';
                ll value = rem*10+digit;
                int quotientDigit = static_cast<int>(value/base);
                rem =value%base;
                if(!(nextQuotient.empty() && quotientDigit==0)){
                    nextQuotient.push_back((char)('0'+quotientDigit));
                }
            }
            result.push_back('0'+rem);
            current = nextQuotient.empty() ? "0" : nextQuotient;
        }
        reverse(begin(result),end(result));
        return result;
    }

    ll C(int n, int k){
        k = min(n-k,k);
        ll perms=1;
        for(int i=n; i>(n-k); i--)perms *= i;
        for(int i=1; i<=k; i++)perms /= i;
        return perms%mod;
    }

    ll f(string s, int b, int idx, int x){  // x --> current-limit
        int n = s.size();
        if(idx==n)return 1;
        if(x > s[idx]-'0')return 0;
        ll ways = C(n-idx+b-x-1,n-idx) - C(n-idx+b-(s[idx]-'0')-1,n-idx);
        ways += f(s,b,idx+1,s[idx]-'0');
        return (ways+mod)%mod;
    }


    string sub(string s){
        int n = s.size();
        while(s[--n]=='0')s[n]='9';
        s[n]--;
        return s;
    }
    int countNumbers(string l, string r, int b) {
        l = convert(sub(l),b);
        r = convert(r,b);
        return (int)((f(r,b,0,0)-f(l,b,0,0) + mod) %mod);
    }
};