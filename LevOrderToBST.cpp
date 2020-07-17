Node* levelOrder(Node* root, int data){
    if(root == NULL){
        Node *nn = new Node(data);
        return nn;
    }
    if(data <= root->data){
        root->left = levelOrder(root->left, data);
    }else{
        root->right = levelOrder(root->right, data);
    }
    return root;
}


Node* constructBst(int arr[], int n)
{
    
    Node *root = NULL;
    for(int i = 0; i < n; i++){
        root = levelOrder(root, arr[i]);
    }
    
    return root;
	
}
