class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {

        vector<string>w1,w2;
        string token;
        stringstream ss1(s1), ss2(s2);

        while(ss1 >> token){
            w1.push_back(token);
        }
        while(ss2 >> token){
            w2.push_back(token);
        }

        int s = 0, l1=w1.size(), l2 = w2.size();
        if(l1>l2){w1.swap(w2);}
        s = 0, l1=w1.size(), l2 = w2.size();
        int e1=l1-1,e2=l2-1;

        while(s<l1 && w1[s] == w2[s])s++;

        while(e1>=0 && w1[e1]==w2[e2]){e1--;e2--;}

        return e1<s;
    }
};