class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for(char ch : s)freq[ch-'a']++;

        s="";
        int currCharIndex = 25;
        while(currCharIndex >= 0){
            if(!freq[currCharIndex]){currCharIndex-- ; continue;}
            int num = min(freq[currCharIndex],repeatLimit);
            s.append(num,'a'+currCharIndex);
            freq[currCharIndex]-=num;

            if(freq[currCharIndex]){
                int smallCharIndex = currCharIndex - 1;
                while(smallCharIndex>=0 && freq[smallCharIndex]==0)smallCharIndex--;
                if(smallCharIndex<0)break;
                
                s.push_back('a'+smallCharIndex);
                freq[smallCharIndex]--;
            }
        }
        return s;
    }
};