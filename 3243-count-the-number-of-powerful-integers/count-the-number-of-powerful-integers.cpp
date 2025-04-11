#define ll long long 
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        ll result = countUpTo(to_string(finish),s,limit)-countUpTo(to_string(start-1),s,limit);
        return result;
    }

private:
    long long countUpTo(const string& numStr, string suffix, int limit){
        int numLen = numStr.length();
        int suffixLen = suffix.length();

        if(numLen < suffixLen)return 0;
        if(numLen == suffixLen)return (numStr >= suffix) ? 1 : 0 ;

        long long count=0;
        int prefixLen = numLen-suffixLen;
        string actualSuffix = numStr.substr(prefixLen);

        for(int i=0; i<prefixLen; i++){
            long long waysForRemaining = pow(limit+1,prefixLen-i-1);
            int currDigit = numStr[i]-'0';
            if(currDigit>limit){
                count += (limit+1)*waysForRemaining;
                return count;
            }
            count += (currDigit*waysForRemaining);
        }

        if(actualSuffix >= suffix)count++;

        return count;
    }
};