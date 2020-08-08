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
    

class Node{
    public : 
        Node *prev, *next;
        int val;
};

class myStack{
    public: 
        Node *head, *mid;
        int cnt;
};
myStack *createMyStack(){
    myStack *ms = new myStack();
    ms->cnt = 0;
    return ms;
};

void push(myStack *ms, int val){
    Node * nn = new Node();
    nn->val = val;
    nn->prev = NULL;
    nn->next = ms->head;
    ms->cnt += 1;

    if(ms->cnt == 1){
        ms->mid = nn;
    }else{
        ms->head->prev = nn;
        if(!(ms->cnt & 1)){
            ms->mid = ms->mid->prev;
        }
    }
    ms->head = nn;
}

int pop(myStack *ms){
    if(ms->cnt == 0)return -1;
    Node *head = ms->head;
    int item = head->val;
    ms->head = head->next;
    if(ms->head != NULL)ms->head->prev = NULL;

    ms->cnt -= 1;
    if(ms->cnt & 1)
        ms->mid = ms->mid->next;
    free(head);
    return item;
}
int findMiddle(myStack *ms){
    if(ms->cnt == 0){
        return -1;
    }
    return ms->mid->val;
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

