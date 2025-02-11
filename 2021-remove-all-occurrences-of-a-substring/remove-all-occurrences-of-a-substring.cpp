class Solution {
    private:
    bool checkMatch(stack<char> &st, string part, int p){
        stack<char> temp = st;
        for(int i=p-1; i>=0; i--){
            if(temp.top() != part[i])return false;

            temp.pop();
        }
        return true;
    }
public:
    string removeOccurrences(string s, string part) {
        int n = s.length(), p = part.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            st.push(s[i]);
            if(st.size()>=p && checkMatch(st,part,p)){
                for(int j=0; j<p; j++)st.pop();
            }
        }

        s = "";
        while (!st.empty()) {
            s = st.top() + s;
            st.pop();
        }

        return s;
    }
};