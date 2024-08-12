class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int h = 0;
        int n = 0;

        while (h < haystack.size()) {
            if (haystack[h] == needle[n]) {
                int start = h;
                while (n < needle.size() && h < haystack.size() && haystack[h] == needle[n]) {
                    h++;
                    n++;
                }
                if (n == needle.size()) return start;
                n = 0;
                h = start + 1;
            } else {
                h++;
            }
        }
        
        return -1;
    }
};
