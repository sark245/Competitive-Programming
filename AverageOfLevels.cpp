#include<iostream>
#include<vector>
#include<bits/stdc++.h>
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

// This is a functional problem. You have to complete this function.
// It takes as input the root node of the given tree.
vector<double> averageOfLevels(TreeNode* root) {
    // Write your code here
    vector<double>res;
    if(root == nullptr){
        res.push_back(0.0);     //Condition for Empty Tree
        return res;
    }
    double temp = 0;        //To store sum at each level

    queue<TreeNode*>q;
    q.push(root);
    q.push(nullptr);

    res.push_back(root->val);
    int count = 0;
    while(!q.empty()) {
        TreeNode *rem = q.front();
        q.pop();

        if (rem == nullptr) {
            if(count != 0) res.push_back(temp / count);
            if (q.empty())break;
            q.push(nullptr);
            temp = 0;
            count = 0;
        } else {
            temp += root->val;
            count++;
            if (root->left != nullptr) {
                q.push(root->left);
            }
            if (root->right != nullptr) {
                q.push(root->right);
            }

        }
    }
    return res;

}

int main(int argc, char** argv){
    int x;
    cin>>x;
    cin.ignore();
    string line;
    getline(cin, line);
    TreeNode* root = stringToTreeNode(line);
    vector<double> res = averageOfLevels(root);
    for(double i: res){
        cout<<i<<" ";
    }
    cout<<endl;
}