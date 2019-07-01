//
// Created by sark2 on 01-07-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define cases int t;cin>>t;while(t--)
typedef long double ld;

struct Node{
    char data;
    bool end;
    unordered_map<char, Node*> children;
    Node(){}
    Node(char data) : data(data), end(false) {}

};

class Trie{

    Node *root;

    int nodes;
    int words;
    bool search(Node *n, string s, int idx){
        if(idx == s.length()){
            return n->end;
        }
        char ch = s[idx];
        if(n->children.count(ch)==0){
            return false;
        }
        else{
            Node* child = n->children[ch];
             search(child, s, idx+1);
        }
    }
    void add(Node* temp, string word, int index){
        char ch = word[index];
        if(index == word.length()){
            this->words++;
            temp->end = true;
            return;
        }
        if(temp->children.count(ch) == 0){
            this->nodes++;

            Node *nn = new Node(ch);

            temp->children[ch] = nn;
            add(temp->children[ch], word ,index +1);
        }
        else{
            Node *child = temp->children[ch];
            add(child, word, index+1);
        }

    }
    void display(Node* temp, string wsf){
        if(temp->end){
            cout<<wsf<<endl;
        }
        for(auto i : temp->children){
            display(i.second, wsf + string(1,i.first));
        }
    }
    void remove(Node* temp, string word, int index){

        if(index == word.length()) {
            words--;
            temp->end = false;
            return;
        }

        char ch = word[index];
        Node *child = temp->children[ch];
        remove(child, word, index + 1);

        if(!child->end && child->children.empty()){
            nodes--;
            temp->children.erase(ch);
            delete child ;
        }
    }
    void displayTrie(Node *temp){

        cout<<temp->data<<" : ";
        for(auto i : temp->children){
            cout<<i.first<<", ";
        }
        cout<<". "<<endl;

        for(auto i : temp->children){
            displayTrie(i.second);
        }

    }

public:
    Trie(){
        root  = new Node('$');
        nodes = 1;
        words = 0;

    }
    bool search(string s){
        return search(root, s, 0);
    }
    void add(string word){
        if(!search(word))
            add(root, word, 0);
    }
    void display(){

        display(root, "");
    }

    void remove(string word){
        if(search(word))
            remove(root, word, 0);
    }
    void displayTrie(){
        displayTrie(root);
    }


};

int main() {
    IOS
    Trie t;

    t.add("yes");
    t.add("yesa");
    t.displayTrie();
    t.remove("yesa");
    t.displayTrie();
    t.remove("yes");
    t.displayTrie();


}
