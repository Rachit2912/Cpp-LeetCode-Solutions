class Solution {
    private int[] getCoords(int val, int n){
        int r = n-1- ((val-1)/n);
        int c = (val-1)%n;

        if((n%2==1 && r%2==1) || (n%2==0 && r%2==0))c=n-1-c;
        // int[] coords = {r,c};
        return new int[]{r,c};
    }

    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        boolean[][] vis = new boolean[n][n];
        Queue<Integer> q = new LinkedList<>();

        q.offer(1);
        vis[n-1][0] = true;

        int steps = 0;

        while(!q.isEmpty()){
            int size = q.size();

            while(size-- > 0){
            int curr = q.poll();

            if(curr == n*n)return steps;

            for(int dice=1; dice<7; dice++){
                int next = curr+dice;
                if(next > n*n)break;

                int[] coords = getCoords(next,n);

                int r = coords[0], c = coords[1];

                if(vis[r][c] == true)continue;

                vis[r][c]=true;

                if(board[r][c] == -1){
                    q.offer(next);
                }else{
                    q.offer(board[r][c]);
                }
            }
            }
            steps++  ;
        }
        return -1 ;
    }
}