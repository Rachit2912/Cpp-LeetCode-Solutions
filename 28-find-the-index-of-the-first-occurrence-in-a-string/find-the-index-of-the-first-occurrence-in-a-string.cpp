class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> idxs = kmp(haystack,needle);
        if(idxs.size()==0)return -1;    
        return idxs[0];
    }

    vector<int> kmp(string text, string pattern){
        int lenT = text.size();
        int lenP = pattern.size();
        vector<int> ans;
        vector<int> lps(lenP,0);
        calcLPS(pattern,lps);

        int i=0,j=0;
        while(i<lenT){
            if(text[i]==pattern[j]){
                i++;j++;
            }

            if(j==lenP){
                ans.push_back(i-j);
                j = lps[j-1];
            } else if(i<lenT && text[i]!=pattern[j]){
                if(j!=0)j=lps[j-1];
                else i++;
            }
        }
        return ans;
    }

    void calcLPS(string pattern, vector<int> &lps){
        lps[0]=0;
        int lenP = pattern.length();
        int length = 0;

        int i=1;
        while(i<lenP){
            if(pattern[length]==pattern[i]){
                length++;
                lps[i]=length;
                i++;
            } else{
                if(length!=0)length=lps[length-1];
                else {lps[i]=0;i++;}
            }
        }
    }

    
};