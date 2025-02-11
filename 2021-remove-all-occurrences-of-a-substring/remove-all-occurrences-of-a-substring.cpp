class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != -1){
            int i = s.find(part);
            s = s.substr(0,i) + s.substr(i+part.length());
        }
        return s;
    }
};