class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return solve(to_string(finish),s,limit)-solve(to_string(start-1),s,limit);
    }

private:    
    long long solve(const string &str, string &ipSuffix, int limit){

        if(stoll(str) < stoll(ipSuffix))return 0;
        long long cnt=0;

        int remainDigits = str.length() - ipSuffix.length();
        string pichheWaliStr = str.substr(remainDigits);

        for(int i=0; i<remainDigits; i++){
            int digit = str[i]-'0';

            if(digit<=limit){
                cnt += (digit * pow(limit+1, remainDigits-i-1));
            }else{
                cnt += (pow(limit+1,remainDigits-i));
                return cnt;
            }
        }

        if(pichheWaliStr >= ipSuffix)cnt++;

        return cnt;
    }
};