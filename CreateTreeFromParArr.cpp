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
    Node(){}
    Node(int x) : val(x), left(NULL), right(NULL){}
};

void createNode(int par[], int i, Node *created[], Node **root){
    if(created[i] != NULL)return;

    created[i] = new Node(i);
    if(par[i] == -1){
        *root = created[i];
        return;
    }

    if(created[par[i]] == NULL)
        createNode(par, par[i], created, root);
    
    Node *p = created[par[i]];

    if(p->left == NULL)p->left = created[i];
    else p->right = created[i];
}

Node *createTree(int par[], int n){
    Node *created[n];
    for(int i = 0; i < n; i++){
        created[i] = NULL;
    }
    Node *root = NULL;
    for(int i = 0; i < n; i++)
        createNode(par, i, created, &root);
    return root;
}

void inorder(Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout << root->val << " "; 
        inorder(root->right); 
    } 
} 


int main(){
   IOS

    int parent[] =  {-1, 0, 0, 1, 1, 3, 5}; 
    int n = sizeof parent / sizeof parent[0]; 
    Node *root = createTree(parent, n); 
    cout << "Inorder Traversal of constructed tree\n"; 
    inorder(root);



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

