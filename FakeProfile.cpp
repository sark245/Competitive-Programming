//
// Created by sark2 on 19-06-2019.
//
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

//this is a functional problem
void findIfFake(string s){

    //write your code here
    unordered_set<char>set;
    for(int i = 0; i<s.length(); ++i){
        set.insert(s[i]);
    }
    if(set.size()%2 ==1 ){
        cout<<"HE!";
    }
    else cout<<"SHE!";

}
int main(int argc, char**argv){
    string s;
    getline(cin,s);
    findIfFake(s);
}
