class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;

        int[] result = prices.clone();
        Stack<Integer> s = new Stack<>();

        for(int i=0; i<n; i++){
            while(!s.isEmpty() && prices[s.peek()] >= prices[i]){
                result[s.peek()] -= prices[i];
                s.pop();
            }
            s.add(i);
        }
        return result;
        
    }
}