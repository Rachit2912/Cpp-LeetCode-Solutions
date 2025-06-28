class Solution {
public:
    string ans="";
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();
        vector<int> freq(26,0);
        for(auto ch : s)freq[ch-'a']++;

        vector<bool>canUse(26,false);
        for(int i=0; i<26; i++){
            if(freq[i]>=k){
                canUse[i]=true;
                freq[i] /= k;
            }
        }

        int maxLen = n/k;

        for(int len=maxLen; len>0; len--){
            vector<int> tempFreq = freq;
            string curr="";
            if(genSubseq_and_Chk(s,curr,canUse,tempFreq,k,len))return ans;
        }

        return ans;
    }

private:
    bool genSubseq_and_Chk(string &s,string &curr,vector<bool> &canUse,vector<int> &freq,int k, int len){

        // base case 
        if(curr.length() == len){
            if(isSubseq(curr,s,k)){
                ans = curr;
                return true;
            }
            return false;
        }
        

        for(int i=25; i>-1; i--){
            if(canUse[i]==false || freq[i]==0)continue;

            // do 
            char ch = i+'a';
            curr.push_back(ch);
            freq[i]--;

            //explore 
            if(genSubseq_and_Chk(s,curr,canUse,freq,k,len))return true;

            //undo
            curr.pop_back();
            freq[i]++;
        }
        return false;
    }

    bool isSubseq(string &sub, string &s, int k){
        int i=0,j=0;
        int L = sub.length(), n =s.length();

        while(i<n && j<k*L){
            if(s[i] == sub[j%L])j++;
            i++;
        }
        return j==(L*k);
    }

};