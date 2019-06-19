//
// Created by sark2 on 19-06-2019.
//

#include<bits/stdc++.h>
using namespace std;

class  operation{
public:
    char op;
    int key;

    operation(char op,int key){
        this->key=key;
        this->op=op;
    }

};

//Don't make any changes here

void display(vector<operation>& list) {

    for (int i = 0; i < list.size(); i++) {
        cout<<list[i].op<<" "<<list[i].key<<endl;
    }
    cout<<endl;
}

//this is a functional problem

void print(vector<operation> & v){
    //  Write your code here
    unordered_map<int, int>freq;

    for(auto i : v){
        if(i.op == 'A') freq[i.key]++;
        else if(freq.find(i.key) != freq.end()){
            freq[i.key]--;
            if(freq[i.key]==0)
                freq.erase(i.key);
        }
        cout<<freq.size()<<"\n";

    }


}


int main(int argc,char** argv){
    // Input for length of array.
    int N ;
    cin>>N;
    vector<operation> v;

    // Input for array elements.
    for (int i = 0; i < N; i++) {
        char a;
        int k;
        cin>>a>>k;
        operation ob(a,k);
        v.push_back(ob);
    }

    print(v);
}
