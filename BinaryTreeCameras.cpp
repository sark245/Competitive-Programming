#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

// TreeNode class for a node of a Binary Search Tree
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// utility function to display a binary tree
void display(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    string str = "";

    str += node->left == NULL ? "." : to_string(node->left->val);
    str += " <= " + to_string(node->val) + " => ";
    str += node->right == NULL ? "." : to_string(node->right->val);

    cout<<str<<endl;

    display(node->left);
    display(node->right);
}

// creation of tree from array by level order, -1 says there is no node
TreeNode* levelOrder(vector<int> &arr) {

    vector<TreeNode*> nodes(arr.size());
    for (int i = 0; i < nodes.size(); i++) {
        if (arr[i] != -1) {
            TreeNode* t = new TreeNode(arr[i]);
            nodes[i] = t;

            if (i > 0) {
                int pi = (i - 1) / 2;
                if (i == 2 * pi + 1) {
                    nodes[pi]->left = nodes[i];
                } else {
                    nodes[pi]->right = nodes[i];
                }
            }
        }
    }
    TreeNode* root = nodes[0];
    return root;
}

// This is a functional problem. You have to complete this function.
// It takes as input the root of the given tree. It should return the minimum number of cameras required.
 unordered_map<TreeNode*,int>map;


int minCameraCover(TreeNode* root) {
    // write your code here
    if(root == nullptr) return 0;

    if(map.find(root) != map.end())
        return map[root];

    int b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0;
    //Left Subtree
    if(root->left != nullptr) {
        b = minCameraCover(root->left);
        if (root->left->left != nullptr) {
            d = minCameraCover(root->left->left);
            if (root->left->left->left != nullptr) {
                h = minCameraCover(root->left->left->left);
            }
            if (root->left->left->right != nullptr) {
                i = minCameraCover(root->left->left->right);
            }
        }
        if (root->left->right != nullptr) {
            e = minCameraCover(root->left->right);
            if (root->left->right->left != nullptr)
                j = minCameraCover(root->left->right->left);
            if (root->left->right->right != nullptr)
                k = minCameraCover(root->left->right->right);
        }
    }

    //Right Subtree
    if(root->right != nullptr) {
        c = minCameraCover(root->right);
        if (root->right->left != nullptr) {
            f = minCameraCover(root->right->left);
            if (root->right->left->left != nullptr)
                l = minCameraCover(root->right->left->left);
            if (root->right->left->right != nullptr)
                m = minCameraCover(root->right->left->right);
        }
        if (root->right->right != nullptr) {
            g = minCameraCover(root->right->right);
            if (root->right->right->left != nullptr)
                n = minCameraCover(root->right->right->left);
            if (root->right->right->right != nullptr)
                o = minCameraCover(root->right->right->right);
        }
    }

    int f1 = 1 + d + e + f + g;
    int f2 = min(1 + b + l + m + n + o, 1 + c + h + i + j + k);
    int f3 = min(f1,f2);
    map[root] = f3;
    return f3;

}


int main(int argc, char** argv){
    // length of array representing the tree
    int len;
    cin>>len;

    vector<int> arr(len);
    for (int i = 0; i < len; i++) {
        cin>>arr[i];
    }
    TreeNode* root = levelOrder(arr);
    cout<<minCameraCover(root);
}