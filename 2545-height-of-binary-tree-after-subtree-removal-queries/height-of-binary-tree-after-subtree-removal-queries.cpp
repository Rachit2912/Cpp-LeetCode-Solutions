/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 const int limit = 1e5+1;
class Solution {
public:

  // bruteforce : har baar node ko delete kro & then fir height ko calc. kro har baar 
        /* optimized : 
        har level pr 1 node hoga jisse max. height find ho rhi hogi, agr vo delete ho rha hoga to 
        2ndmaxheight chk krenge nhi to koi dikkat hi nhi h 
        agr maxht. delete nhi ho rhi to uss node ki khud ki jo ht h jo ki maxht. bhi h vo + jo node 
        delete ho rha h uski level -1 (bcoz isme height edge ko maana h )

        iska means we need to store level of each node, height of each node, maxht. at each level, 
        2ndmaxht @ each level

        */

        
        int levels[limit];
        int height[limit];
        int maxHt[limit];
        int secmaxHt[limit];

        int findHt(TreeNode* root, int level){
            if(!root)return 0;

            // setting the current level & height : 
            levels[root->val] = level;
            height[root->val] = max(findHt(root->left,level+1),findHt(root->right,level+1))+1;

            // if currHt > maxHt @ curr. level then update : 
            if(height[root->val] > maxHt[level]){
                secmaxHt[level] = maxHt[level];
                maxHt[level] = height[root->val];
            }

            // else if currHt > secmaxHt @ curr. level then update  :
            else if(height[root->val] > secmaxHt[level]){
                secmaxHt[level] = height[root->val];
            }


            return height[root->val];   // returning the final height of the current node
        }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        findHt(root,0);

        vector<int> result;

        for(auto &node : queries){

            int L = levels[node];

            // int currRes = L + R - 1; 
            // now R can be maxHt or secmaxHt depending on the node we are deleting
            int currRes = L + (maxHt[L] == height[node] ? secmaxHt[L] : maxHt[L])  - 1;
            result.push_back(currRes);

        }
        return result;
    }
};