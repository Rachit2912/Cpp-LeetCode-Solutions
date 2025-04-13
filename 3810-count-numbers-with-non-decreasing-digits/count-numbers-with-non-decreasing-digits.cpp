#define ll long long 
class Solution {
public:
    ll dp[401][2][10];
    const int MOD=1e9+7;

    string subtractOne(string s){
        int i=s.size()-1;
        while(i>=0){
            if(s[i]>'0'){s[i]--;break;}
            s[i--]='9';
        }
        if(s[0]=='0' &&s.size()>1){s.erase(0,s.find_first_not_of('0'));}

        return s;
    }

    //   string divmodString(const string &num, int base, int &rem_out) {
    //     string quotient;
    //     quotient.reserve(num.size());
    //     int carry = 0;
    //     for (char c : num) {
    //         int d = c - '0';
    //         int cur = carry * 10 + d;
    //         int q = cur / base;
    //         carry = cur % base;
    //         if (!quotient.empty() || q != 0)
    //             quotient.push_back(char('0' + q));
    //     }
    //     rem_out = carry;
    //     return quotient.empty() ? "0" : quotient;
    // }

    // string convertToBaseX(const string &decimalStr, int base) {
    //     if (decimalStr == "0") return "0";
    //     static const char *digits = "0123456789";
    //     string n = decimalStr;
    //     string result;
    //     while (n != "0") {
    //         int rem;
    //         n = divmodString(n, base, rem);
    //         result.push_back(digits[rem]);
    //     }
    //     reverse(result.begin(), result.end());
    //     return result;
    // }

    string convertToBaseX(const string &decimalStr, int base) {
    // Handle edge cases
    if (decimalStr.empty() || decimalStr == "0") return "0";
    if (base < 2 || base > 10) return ""; // Invalid base (adjust per needs)
    
    // Initialize variables
    string result;
    string num = decimalStr; // Working copy
    result.reserve(decimalStr.size()); // Prevent reallocations
    
    // Process until num is zero
    while (num != "0") {
        int remainder = 0;
        string quotient;
        quotient.reserve(num.size());
        
        // Divide num by base
        for (char c : num) {
            int digit = c - '0';
            int current = remainder * 10 + digit;
            quotient.push_back('0' + (current / base));
            remainder = current % base;
        }
        
        // Append remainder as digit
        result.push_back('0' + remainder);
        
        // Update num, removing leading zeros
        size_t first_non_zero = quotient.find_first_not_of('0');
        num = (first_non_zero == string::npos) ? "0" : quotient.substr(first_non_zero);
    }
    
    // Reverse to get correct order
    reverse(result.begin(), result.end());
    return result;
    }

    ll f(const string &num, int base, int pos, int tight, int prevDigit){
        if(pos==num.size())return 1;
        ll &res = dp[pos][tight][prevDigit];
        if(res != -1)return res;
        res=0;
        int high = tight ? (num[pos]-'0') : (base-1);
        for(int d=prevDigit; d<=high; d++){
            res += f(num,base,pos+1,tight&&(d==high),d);
        }
        return res;
    }


    int countNumbers(string l, string r, int b) {
        string l1 = (l=="0"?"0":subtractOne(l));
        string lb = convertToBaseX(l1,b);
        string rb = convertToBaseX(r,b);
        memset(dp,-1,sizeof(dp));
        ll cntR = f(rb,b,0,1,0);
        memset(dp,-1,sizeof(dp));
        ll cntL = f(lb,b,0,1,0);
        ll ans = (cntR-cntL+MOD)%MOD;
        return (int)ans;
    }
};