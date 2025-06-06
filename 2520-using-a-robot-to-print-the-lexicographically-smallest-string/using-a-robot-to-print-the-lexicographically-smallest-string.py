class Solution:
    def robotWithString(self, s: str) -> str:
        t,paper="",""
        n = len(s)
        pichu = [None]*n
        pichu[n-1] = s[n-1]
        for i in range(n-2,-1,-1):
            pichu[i] = min(pichu[i+1],s[i])
        
        for i in range(n):

            currCharAts = s[i]

            t += currCharAts
            if i!=n-1:
                rightChotaElt = pichu[i+1]
            else :
                rightChotaElt = 'z'+'1'
            

            # if len(t)!=0 and t[-1] < currCharAts : 
            while len(t) > 0  and rightChotaElt >= t[-1] :
                paper += t[-1]
                t = t[0:len(t)-1]
            
        while len(t) > 0 :
            paper += t[-1]
            t = t[0:len(t)-1]
            
        return paper
            
            
        





        