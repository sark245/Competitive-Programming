//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);
    
struct Node{
    int val;
    Node *left, *right;
};

Node *join(Node *L, Node *R){
    if(L == NULL)return R;
    if(R == NULL)return L;

    Node *leftTail = L->left;
    Node*rightTail = R->left;

    leftTail->right = R;
    R->left = leftTail;

    L->left = rightTail;
    rightTail->right = L;
    return L;
}

Node *bTreetoCLL(Node *root){
    if(root == NULL)return NULL;
    Node *L = bTreetoCLL(root->left);
    Node *R = bTreetoCLL(root->right);
    root->left = root;
    root->right = root;

    return join(join(L, root), R);
}


int main(){
   IOS

    







}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1) res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

