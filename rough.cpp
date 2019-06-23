// C program for different tree traversals
#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
 string s = "";
void printPostorder(struct Node* node) {


    if (node == NULL){

        s = s.substr(0,s.length()-1);
        return;
        }
    s += "0";
    printPostorder(node->left);

    s+="1";
    printPostorder(node->right);

    cout << node->data << " "<<s<<" ";
    s = s.substr(0,s.length()-1);

}

/* Driver program to test above functions*/
int main()
{
    struct Node *root = new Node(1);
    root->left			 = new Node(2);
    root->right		 = new Node(3);
    root->right->left	 = new Node(4);
    root->right->left->left = new Node(5);
    root->right->left->right = new Node(6);
    root->right->right = new Node(7);

    //cout << "\nPreorder traversal of binary tree is \n";
  //  printPreorder(root);

   // cout << "\nInorder traversal of binary tree is \n";
    //printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    return 0;
}
