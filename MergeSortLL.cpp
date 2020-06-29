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
    int data;
    Node* next;
};


Node* SortedMerge(Node *a, Node *b);


void FrontBackSplit(Node* src, Node **frontRef, Node **backRef);

void MergeSort(Node **headRef){
    Node* head  = *headRef;
    Node *a, *b;

    if((head == NULL) or (head->next== NULL)){
        return ;
    }

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}

Node* SortedMerge(Node *a, Node *b){
    Node* result = NULL;
    if(a == NULL)return b;
    else if(b == NULL)return a;

    if(a->data <= b->data){
        result = a;
        result->next = SortedMerge(a->next, b);
    }else{
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}

void FrontBackSplit(Node* src, Node** frontRef, Node** backRef){
    Node *fast, *slow;
    slow = src;
    fast = src->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = src;
    *backRef = slow->next;
    slow->next = NULL;
}

void priintList(Node* node){
    while(node != NULL){
        cout<<node->data<<" -> ";
        node = node->next;
    }
}

void push(Node **headRef, int new_data){
    Node *nn = new Node();
    
    nn->data = new_data;
    nn->next = (*headRef);
    (*headRef) = nn;
}



int main(){
   IOS

   Node* res = NULL;
   Node *a = NULL;

   push(&a, 15);
   push(&a, 10);
   push(&a, 5);
   push(&a, 20);
   push(&a, 3);
   push(&a, 100);
   MergeSort(&a);

   priintList(a);
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

