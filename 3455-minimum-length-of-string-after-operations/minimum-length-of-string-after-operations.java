class Solution {
    public int minimumLength(String s) {
        HashMap<Character,Integer> freq = new HashMap<>();
        for(char ch : s.toCharArray()){
            freq.put(ch,freq.getOrDefault(ch,0)+1);
        }

        int delCnt = 0;
        for(int f: freq.values()){
            if(f%2==1)delCnt += (f-1);
            else delCnt +=(f-2);
        }
        return (s.length()-delCnt);
        
    }
}