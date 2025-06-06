class Solution {
public:
    string robotWithString(string s) {
        unordered_map<int,int> freq;
        for(char c : s)freq[c]++;

        stack<char> stk;
        string t,paper;
        char minChar = 'a';
        for(char c : s){
            stk.push(c);
            freq[c]--;

            while(minChar != 'z' && freq[minChar] ==0)minChar++;

            while(!stk.empty() && stk.top() <= minChar){
                paper.push_back(stk.top());
                stk.pop();
            }
        }
        return paper;
    }
};