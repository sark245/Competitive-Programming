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

Node* newNode(int v){
    Node* nn = new Node();
    nn->val = v;
    nn->left = NULL, nn->right = NULL;
}

int traverse(Node *root, int* tilt){
    if(!root)return 0;
    int left = traverse(root->left, tilt);
    int right = traverse(root->right, tilt);
    *tilt += abs(left - right);
    return left + right + root->val;
}

int Tilt(Node *root){
    int tilt = 0;
    traverse(root, &tilt);
    return tilt;
}


int main(){
   IOS

    Node* root = NULL; 
    root = newNode(4); 
    root->left = newNode(2); 
    root->right = newNode(9); 
    root->left->left = newNode(3); 
    root->left->right = newNode(8); 
    root->right->right = newNode(7); 
    cout << "The Tilt of whole tree is " << Tilt(root); 
    return 0; 

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

