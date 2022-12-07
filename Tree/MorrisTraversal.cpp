void MorrisInorder(TreeNode* root){
    TreeNode* curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->val<<" ";
            curr = curr->right;
        }
        else{
            TreeNode* pred = curr->left;
            while(pred->right!=curr && pred->right!=NULL) 
                pred=pred->right;
            if(pred->right==NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                cout<<curr->val<<" ";
                curr = curr->right;
            }
        }
    }
}
