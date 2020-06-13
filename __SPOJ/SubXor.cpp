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
    int cl, cr;
    Node* left, *right;
    Node():cl(0), cr(0), left(NULL), right(NULL){}
};



void insert(Node* root, int x){
    
    for(int i = 20; i >= 0; --i){
        if(x & (1<<i)){
            if(root->right == NULL)
                root->right = new Node();
            root->cr++;
            root = root->right;
        }else{
            if(root->left == NULL)
                root->left = new Node();
            root->cl++;
            root = root->left;
        }
    }
}

ll maxXor(Node* root, int x, int k){
    ll ret = 0;

    if(root == NULL)return ret;

    for(int i = 20; i >= 0; --i){
        int p = (x & (1 << i)) > 0;
        int q = (k & (1 << i)) > 0;
        if(p == 1 && q == 0){
            if(root->right != NULL)root= root->right;
            else return ret;
        }else if(p == 1 && q == 1){
            ret += root->cr;
            if(root->left == NULL)return ret;
            root = root->left;
        }else if(p == 0 && q == 1){
            ret += root->cl;
            if(root->right == NULL)return ret;
            root = root->right;
        }else if(p == 0 && q == 0){
            if(root->left != NULL)
                root = root->left;
            else return ret;
        }
        
    }

    return ret;
}

void inorder_des(Node* root){
    if(root == NULL)return;

    inorder_des(root->left);
    delete(root);
    inorder_des(root->right);
}




int main(){
   IOS
   int t; cin>>t;
   while(t--){

        int n, k; cin>>n>>k;

        vi a(n, 0);        
        Node* root = new Node();

        for(int  i = 0; i < n; i++){
            cin>>a[i];
        }

        ll ans = 0;
        int p = 0;
        insert(root, 0);         

        for(int i = 0; i < n; i++){
            p ^= a[i];
            ans += maxXor(root, p, k);
            insert(root, p);
        }

        cout<<ans<<"\n";
        inorder_des(root);
        
        
   }

}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1)
        res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

