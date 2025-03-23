class Solution {
    final int MOD = (int)1e9+7;
    public int countPaths(int n, int[][] roads) {
        List<List<int[]>> graph = new ArrayList<>();
        for(int i=0; i<n; i++)graph.add(new ArrayList<>());

        for(int[] r : roads){
            int u = r[0], v = r[1], t = r[2];
            graph.get(u).add(new int[] {v,t});
            graph.get(v).add(new int[] {u,t});
        }

        PriorityQueue<long[]> minHeap = new PriorityQueue<>(Comparator.comparingLong(a->a[0]));

        long[] times = new long[n];
        Arrays.fill(times,Long.MAX_VALUE);
        int[] pathCnt = new int[n];
        times[0] = 0; pathCnt[0]=1;
        minHeap.offer(new long[] {0,0});

        while(!minHeap.isEmpty()){
            long[] top = minHeap.poll();
            long currTime = top[0];
            int currNode = (int)top[1];

            if(currTime > times[currNode])continue;

            for(int[] ngbrNodes : graph.get(currNode)){
                int ngbr = ngbrNodes[0], roadTime = ngbrNodes[1];

                if(currTime + roadTime < times[ngbr]){
                    times[ngbr] = currTime + roadTime;
                    pathCnt[ngbr] = pathCnt[currNode];
                    minHeap.offer(new long[] {times[ngbr],ngbr});
                }else if(currTime + roadTime == times[ngbr]){
                    pathCnt[ngbr] += pathCnt[currNode];
                    pathCnt[ngbr] %= MOD;
                }
            }
        }
        return pathCnt[n-1];
    }
}