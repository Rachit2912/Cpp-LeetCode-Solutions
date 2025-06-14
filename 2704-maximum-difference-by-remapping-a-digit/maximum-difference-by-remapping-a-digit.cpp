class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        int pos = s.find_first_not_of('9');
        if(pos != string::npos){
            char a = s[pos];
            replace(s.begin(),end(s),a,'9');
        }

        char b = t[0];
        replace(t.begin(),end(t),b,'0');
        return stoi(s)-stoi(t);
    }
};