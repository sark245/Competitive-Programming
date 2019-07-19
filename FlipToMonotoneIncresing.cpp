#include<iostream>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input a string
// It should return required output.
int minFlipsMonoIncr(string &s) {
    // Write your code here
    int a,b;
    if(s.substr(0,2) == "00"){
        a = 1;
        b = 0;
    }
    if(s.substr(0,2) == "01"){
        a = 0;
        b = 1;
    }
    if(s.substr(0,2) == "10"){
        a = 2;
        b = 1;
    }
    else{
        a = 1;
        b = 2;
    }
    for(int i = 2; i < s.length(); i++){
        if(s[i] == '0'){
            a = min(a,b) + 1;
            b = b;
        }
        else{
            a = min(a,b);
            b++;
        }
    }


    return min(min(a,b), (int)(s.length()-b));


}

int main(int argc, char** argv){
    string s;
    cin>>s;
    cout<<minFlipsMonoIncr(s);
}