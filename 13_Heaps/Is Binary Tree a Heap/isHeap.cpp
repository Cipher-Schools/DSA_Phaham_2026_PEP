// GFG Problem - https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1



bool checkMaxHeap(Node* root){
  if(root == NULL) return true;
  
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front->left){
            if(front->data < front->left->data)
                return false;
            q.push(front->left);
        }

        if(front->right){
            if(front->data < front->right->data)
                return false;
            q.push(front->right);
        }
    }
    return true;
}
bool checkCBT(Node* root){
    if(root == NULL) return true;
    bool foundNull = false;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL) foundNull = true;
        else{
            if(foundNull == true) return false;
            q.push(front->left);
            q.push(front->right);
        }
    }
    return true;
}
bool isHeap(Node* tree) {
    return checkCBT(tree) && checkMaxHeap(tree);
}