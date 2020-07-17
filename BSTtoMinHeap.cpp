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
    Node(int v) : val(v), left(NULL), right(NULL){}
};

void printLevelOrder(Node *root){
    if(root == NULL)return;

    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int nc = sz(q);
        while(nc > 0){
            Node *nn = q.front();
            cout<<nn->val<<" ";
            q.pop();
            if(nn->left)q.push(nn->left);
            if(nn->right)q.push(nn->right);
            --nc;
        }cout<<"\n";
    }
}


void BSTtoSortedLL(Node *root, Node** head_ref){
    if(root == NULL)return;

    BSTtoSortedLL(root->right, head_ref);   
    root->right = *head_ref;    
    if(*head_ref != NULL)(*head_ref)->left = NULL;

    *head_ref = root;
    BSTtoSortedLL(root->left, head_ref);
}

void SortedLLtoMinHeap(Node* &root, Node* head){
    if(head == NULL)return;

    queue<Node* >q;
    root = head;
    head = head->right;
    root->right = NULL;
    q.push(root);

    while(head){
        Node *parent = q.front();
        q.pop();

        Node *L = head;
        head = head->right;
        L->right = NULL;
        q.push(L);
        parent->left = L;
        if(head){
            Node *R = head;
            head = head->right;
            R->right = NULL;
            q.push(R);

            parent->right = R;
        }
    }
}

Node* BSTtoMinHeap(Node *&root){
    Node *head = NULL;
    BSTtoSortedLL(root, &head);
    root = NULL;
    SortedLLtoMinHeap(root, head);
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

