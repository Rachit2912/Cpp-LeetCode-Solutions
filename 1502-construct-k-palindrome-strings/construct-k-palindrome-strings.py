class Solution:
    def canConstruct(self, s: str, k: int) -> bool:

        if len(s)<k:
            return False
        
        if len(s)==k:
            return True

        freq = [0]*26
        for i in s : 
            freq[ord(i) - ord('a')] += 1
        
        oddCount = sum(1 for i in freq if i%2==1)

        return oddCount <= k 

        