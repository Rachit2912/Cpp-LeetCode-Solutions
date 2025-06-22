class Solution {
    public String[] divideString(String s, int k, char fill) {
        List<String> ans = new ArrayList<>();
        int i=0,n=s.length();

        while(i<n){
            int end = Math.min(i+k,n);
            ans.add(s.substring(i,end));
            i+=k;
        }

        String last = ans.get(ans.size()-1);
        int l = last.length();
        if(l<k){
            for(int c=0; c<k-l; c++) last += fill;
            ans.set(ans.size()-1,last);
        }
        return ans.toArray(new String[0]);
    }
}