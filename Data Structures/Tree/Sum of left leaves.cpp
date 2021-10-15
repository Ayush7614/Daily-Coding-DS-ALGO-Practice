
/*Given the root of a binary tree, return the sum of all left leaves.
Example-Input: root = [1]
Output: 0*/


 //Time complexity: O(n)
    //spce complexity: O(width of binary tree)
 
 int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(q.empty()==0)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(q.front()==NULL)
            {
                q.pop();
                if(curr->left==0 && curr->right==0)
                     sum=sum+curr->val;
            }
            if(curr->left!=0)
            {
                q.push(curr->left);
                q.push(NULL);
            }
            if(curr->right!=0)
            {
                q.push(curr->right);
            }
        }
        return sum;
    }