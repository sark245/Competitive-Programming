#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<deque>
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
static int sum = 0;
class BinaryTree {
public:


    int TiltUtil(TreeNode* node){
        if(node == nullptr) return 0;
        int r1 = TiltUtil(node->left);
        int r2 = TiltUtil(node->right);
        int rv = r1 + r2 + node->val;
        sum += abs(r1-r2);

        return rv;
    }
    int findTilt(TreeNode* node) {
        // Write your code here
       int r= TiltUtil(node);
        return sum;
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

//Don't change code of utility function.
TreeNode* stringToTreeNode(string input) {
    int first = input.find_first_not_of(' ');
    int last = input.find_last_not_of(' ');
    input = input.substr(first, (last - first + 1));
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ' ');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        if (!getline(ss, item, ' ')) {
            break;
        }

        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ' ')) {
            break;
        }

        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);

        }
    }
    return root;
}

// Don't make any changes here.
int main(int argc, char** argv){
    string line;
    getline(cin, line);
    TreeNode* root = stringToTreeNode(line);
    BinaryTree b;
    int ret = b.findTilt(root);
    string out = to_string(ret);
    cout<<out;
}