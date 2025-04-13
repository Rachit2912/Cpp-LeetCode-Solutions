#define ll long long 
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        
        auto C = [](int n, int r, ll limit) -> ll{
            if(r>n)return 0;
            r=min(r,n-r);
            ll combs=1;
            for(int i=1; i<=r; i++){
                combs = combs * (n-i+1) /i;
                if(combs>=limit)return limit;
            }
            return combs;
        };

        auto P = [&C](const vector<int> &counts, int positions, ll limit) -> ll{
            ll perms=1;
            int remaining = positions;

            for(int cnt : counts){
                ll ways = C(remaining,cnt,limit);
                perms *= ways;
                if(perms >= limit)return limit;
                remaining -= cnt;
            }
            return perms;
        };

        ll max_perms_needed = k+1LL;

        vector<int> freq(26,0);
        for(char c : s)freq[c-'a']++;

        string mid ="";
        for(int i=0; i<26; i++){
            if(freq[i]&1)mid += ('a'+i);
            freq[i]/=2;
        }


        int halfLen = 0;
        for(int cnt : freq)halfLen += cnt;

        ll totalPals = P(freq,halfLen,max_perms_needed);

        if(k>totalPals)return "";

        string first_half="";
        for(int idx=0; idx<halfLen; idx++){
            for(int c=0; c<26; c++){
                if(freq[c]==0)continue;

                freq[c]--;
                ll palsWithPrefix = P(freq,halfLen-idx-1,max_perms_needed);

                if(k > palsWithPrefix){
                    k -= palsWithPrefix;
                    freq[c]++;
                }else{
                    first_half += ('a'+c);
                    break;
                }
            }
        }

        string res = first_half + mid;
        for(int i=first_half.size()-1; i>=0; i--)res += first_half[i];

        return res;    
    
    }

};