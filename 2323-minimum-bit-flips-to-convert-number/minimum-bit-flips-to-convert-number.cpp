class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int a = 0;
        while (x) {
            a += x & 1;  // Increment if the last bit is 1
            x >>= 1;         // Shift right to process the next bit
        }
        return a;
    }
};