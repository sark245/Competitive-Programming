//
// Created by sark2 on 17-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(){}
    Node(int d):data(d),left(nullptr),right(nullptr){}

};
Node *toBST(int a[],int low,int high){
    if(high == low)
        return nullptr;
    int mid = (low+high-1)/2;
    Node* root = new Node(a[mid]);
        root->left = toBST(a, low, mid);
        root->right = toBST(a, mid + 1, high);

    return root;
}

void preorder(Node* root){
    if(root==nullptr)return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void levelOrder(Node* root){

}
int main() {
    IOS
    int n;
    cin>>n;
    int a[n+1];
    for(int i = 0; i < n; i++)cin>>a[i];

    Node* root = toBST(a,0,n);
    preorder(root);
}
