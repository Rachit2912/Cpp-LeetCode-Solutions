/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int minimumOperations(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int ans = 0;

        while(!q.isEmpty()){
            int size = q.size();
            int[] levels = new int[size];

            for(int i=0;i<size; i++){
                TreeNode front = q.poll();
                levels[i] = front.val;

                if(front.left != null)q.add(front.left);
                if(front.right != null)q.add(front.right);
            }

            ans += getMinSwaps(levels);
        }
        return ans;
    }

    private int getMinSwaps(int[] arr){
        int swaps =0;
        int[] target = arr.clone();
        Arrays.sort(target);

        Map<Integer,Integer> pos = new HashMap<>();
        for(int i=0; i<arr.length; i++){
            pos.put(arr[i],i);
        }

        for(int i=0; i<arr.length; i++){
            if(arr[i] != target[i]){
                swaps++;

                int currPos = pos.get(target[i]);
                pos.put(arr[i],currPos);
                arr[currPos] = arr[i];
            }
        }
        return swaps;
    }
}