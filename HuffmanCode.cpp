//
// Created by sark2 on 21-06-2019.
//
#include<bits/stdc++.h>
using namespace std;
struct feeder{
    string alpha;
    vector<int>frequency;
    feeder(){}
    feeder(string alpha,vector<int> freq) : alpha(alpha), frequency(freq){}

};
struct Node{
    char data;
    int freq;
    Node* left;
    Node* right;
    Node(){}
    Node(char c, int f): data(c), freq(f), left(nullptr), right(nullptr){}
};
struct CompareNode{
    bool operator()(Node* const& n1, Node* const& n2){
        return n1->freq > n2->freq;
    }
};

static string s_so_far = "";
unordered_map<char,string>mp;
stack<string>st;

//For Traveral in the tree and allots string to each Leaf
void Treeorder(struct Node* node) {

    if (node == NULL){
        s_so_far = s_so_far.substr(0,s_so_far.length()-1);
        return;
    }
    s_so_far += "1";
    Treeorder(node->left);

    s_so_far += "0";
    Treeorder(node->right);
    //Work
    if(node->data != '*') {
        st.push(s_so_far);
        mp[node->data] = s_so_far;
    }

    s_so_far = s_so_far.substr(0, s_so_far.length() - 1);


}


class HuffmanCoder{
private:
    unordered_map<char,string>encoder_map;
    unordered_map<string,char>decoder_map;
    feeder dat;
    string encoded;
public:
    HuffmanCoder(){}

    explicit HuffmanCoder(feeder f){
        this->dat = f;
        priority_queue<Node*,vector<Node*>,CompareNode>p;
        for(int i = 0 ; i < f.alpha.length(); i++){
            Node *nn = new Node(f.alpha[i],f.frequency[i]);
            p.push(nn);
        }

        while(p.size() > 1){
            Node *n1 = p.top(); p.pop(); //New Right---> Less Frequency
            Node *n2 = p.top(); p.pop(); //New Left---> Greater Frequency

            Node *temp = new Node('*',n1->freq + n2->freq);   //Established New Node

            temp->left = n2;
            temp->right = n1; //Allot the left and right

            p.push(temp);
        }

        Node *root = p.top();


        Treeorder(root);

        this->encoder_map = mp;
        for(auto i : this->encoder_map){
            this->decoder_map[i.second] = i.first;
        }


    }

    void Encode(){

      //Answer For Encoder lies in Global stack st


      for(int i = 0; i < this->dat.alpha.length(); i++){
         this->encoded += encoder_map[this->dat.alpha[i]];
      }

    }

    void Decode(){

        string temp;

        for(auto i : this->encoded){
            temp += string(1,i);
            if(this->decoder_map.find(temp) != this->decoder_map.end()){
                cout<<this->decoder_map[temp];
                temp.clear();
            }
        }

    }



};






int main(){

    vector<int>v;
    string s;
    cin>>s;
    cout<<s;

    unordered_map<char,int>freq;
    for(auto i : s)freq[i]++;
    string feed;
    for(auto i : freq){
        feed += string(1,i.first);
        v.push_back(i.second);
    }


    feeder f(feed,v);

    /*HuffmanCoder h(f);
    h.Encode();
    h.Decode();*/



}

