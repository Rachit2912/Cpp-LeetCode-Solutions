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
class Solution {
public:
void makeGraph(TreeNode* currNode,TreeNode* prevNode, unordered_map<TreeNode*,vector<TreeNode*>> &graph, unordered_set<TreeNode*> &leaves){
    if(!currNode) return;

    if(!currNode->left && !currNode->right) leaves.insert(currNode);

    if(prevNode){
        graph[prevNode].push_back(currNode);
        graph[currNode].push_back(prevNode);
    }

    makeGraph(currNode->left,currNode,graph,leaves);
    makeGraph(currNode->right,currNode,graph,leaves);
}

    int countPairs(TreeNode* root, int distance) {
        // sbse pehle tree ko graph me convert krdo 
        unordered_map<TreeNode*,vector<TreeNode*>> graph;
        unordered_set<TreeNode*> leaves;

        makeGraph(root,nullptr,graph,leaves);
        // ab graph to bn gya 
        // ab bari bfs ki on the leaf nodes 
        int ans = 0;
        for(auto& leaf : leaves){
            queue<TreeNode*> bfsQueue;
            unordered_set<TreeNode*> visited;
            bfsQueue.push(leaf);
            visited.insert(leaf);

            // har leaf node se bfs kro and try ki agr leaf node uss distance k andar mil jaye to ans++ 
            for(int i =0;i<=distance;i++){// jitni distance allowed wha tak hi jao 
                int size = bfsQueue.size();
                for(int j =0; j<size;j++){
                    TreeNode* currNode = bfsQueue.front();
                    bfsQueue.pop();
                    if(leaves.count(currNode) && currNode!=leaf) ans++ ;

                    if(graph.count(currNode)){
                        for(auto n : graph[currNode]){
                            if(!visited.count(n)){
                                bfsQueue.push(n);
                                visited.insert(n);
                            }
                        }
                    }

                }
            }
        }
        return ans/2 ;
    }
};