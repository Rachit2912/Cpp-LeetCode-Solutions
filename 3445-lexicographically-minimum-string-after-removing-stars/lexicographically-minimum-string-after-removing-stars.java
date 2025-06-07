class Solution {
    public String clearStars(String s) {
        int n = s.length();
        
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
            if (a.ch == b.ch)return Integer.compare(b.index,a.index);
            return Character.compare(a.ch,b.ch); 
        });

        char[] arr = s.toCharArray();

        for (int i = 0; i < n; i++) {
            if (arr[i] != '*') {
                pq.offer(new Pair(arr[i], i));
            }else{
                    Pair top = pq.poll();
                    arr[top.index] = '*'; 
            }
        }

        
        StringBuilder result = new StringBuilder();
        for (char c : arr) {
            if (c != '*') {
                result.append(c);
            }
        }

        return result.toString();
    }

    
    class Pair {
        char ch;
        int index;

        Pair(char ch, int index) {
            this.ch = ch;
            this.index = index;
        }
    }
}
