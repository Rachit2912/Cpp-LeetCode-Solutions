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

    public void inorder(TreeNode root, int k, int[] ctr){
        if(root==null)return;
        inorder(root.left,k,ctr);
        ctr[0]++;
        if(ctr[0]==k)ctr[1]=root.val;
        inorder(root.right,k,ctr);
    }


    public int kthSmallest(TreeNode root, int k) {
        int []ctr = new int[]{0,0};
        inorder(root,k,ctr);
        return ctr[1];
    }
}