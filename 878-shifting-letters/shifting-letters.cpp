class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        shifts[n-1] %= 26;
        for(int i=n-1;i>0;i--){
            shifts[i-1] = (shifts[i-1] + shifts[i])%26;
        }
        for(int i=0;i<n;i++){
            if((s[i]+shifts[i])>122){
                shifts[i] -= (122-s[i]);
                s[i] = 96+shifts[i];
            }
            else{
                s[i] += shifts[i]; 
            }
        }
        return s;
    }
};