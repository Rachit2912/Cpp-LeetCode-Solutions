#define ll long long
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        int d = (n+1)/2;
        int s = pow(10,d-1), e = pow(10,d)-1;
        unordered_set<string> st;


    for(int i= s; i<=e; i++){
        string left = to_string(i);
        string full = "";

        if(n%2==0){
            string right = left;
            reverse(right.begin(),right.end());
            full = left+right;
        }else{
            string right = left.substr(0,d-1);
            reverse(right.begin(),right.end());
            full = left+right;
        }
        
        ll number = stoll(full);
        if(number % k != 0)continue;
        sort(full.begin(), full.end());
        st.insert(full);
    }

    vector<ll> fact(11,1);
    for(int i=1; i<11; i++)fact[i]=(fact[i-1]*i);


    ll ans=0;
    for(const auto &s : st){
        vector<int> freq(10,0);
        for(const auto &ch : s)freq[ch-'0']++;

        int totalLen = s.size();
        int zeros = freq[0];
        int nonZeros = totalLen - zeros;

        ll perms = (nonZeros)*(fact[totalLen-1]);

        for(int i=0; i<10; i++)perms /= fact[freq[i]];

        ans += perms;
    }

    return ans;
    }

};