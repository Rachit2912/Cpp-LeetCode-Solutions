class Solution {
    public int minMaxDifference(int num) {
        String maxNum = Integer.toString(num);
        String minNum = maxNum;
        int n = maxNum.length();

        char ch = ' ';
        for(int i=0; i<n; i++){
            if(maxNum.charAt(i) != '9'){
                ch = maxNum.charAt(i);
                break;
            }
        }

        if(ch != ' ')maxNum = maxNum.replace(ch,'9');

        ch = minNum.charAt(0);
        minNum = minNum.replace(ch,'0');

        return Integer.parseInt(maxNum) - Integer.parseInt(minNum);
    }
}