// visit left, then it'sright most then connect it's right to parent
#include<iostream>
#include<vector>

using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node(int val){
    data = val;
    left = nullptr;
    right = nullptr;
  }
}

vector<int> Morris_Traversal(Node* root) {
    vector<int> result;
    Node* curr = root;

    while (curr != nullptr) {

        if (curr->left == nullptr) {
            result.push_back(curr->data);
            curr = curr->right;
        }
        else {
            Node* temp = curr->left;

            // Find inorder predecessor
            while (temp->right != nullptr && temp->right != curr) {
                temp = temp->right;
            }

            // If thread not created
            if (temp->right == nullptr) {
                temp->right = curr;   // create thread
                curr = curr->left;
            }
            else {
                temp->right = nullptr;   // remove thread
                result.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return result;
}