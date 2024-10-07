class Solution {
public:
    int minLength(string s) {
        string s1 ="";
        int n = s.size();
        stack<char> st;
        int i(0);
        while(i < n){

             if (st.empty()) {
                st.push(s[i]);
                i++;
                continue;
            }

            if((st.top()== 'A'&& s[i] == 'B')||(st.top()=='C'&&s[i]=='D')){
                st.pop();
            }

            else{st.push(s[i]);}
            i++;
        }
        return st.size();
    }
};