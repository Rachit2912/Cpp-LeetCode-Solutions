class Solution {
private : 

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

public:
    string shortestPalindrome(string s) {

        string reversed = string(s.rbegin(),s.rend());
        string comb = s+"#"+reversed;
        vector<int> pre = prefix_function(comb);

        int longestPalLength = pre[comb.length()-1];

        string thatNeedToBeReversed = reversed.substr(0,reversed.length()-longestPalLength);
        return thatNeedToBeReversed+s;

    }
};