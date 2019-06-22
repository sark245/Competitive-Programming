#include<iostream>
#include<vector>
//
// Created by sark2 on 22-06-2019.
//
#pragma GCC optimize("O3")

//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)
#pragma GCC optimize("unroll-loops")

// -------------------</optimizations>--------------------)
#include <bits/stdc++.h>


using namespace std;
#define IOS    cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n)    for(int i = 1; i <= (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define cases int t;cin>>t;while(t--)
typedef long double ld;

typedef pair<int, int> pii;
//typedef vector<pii>vii;
typedef vector<int> vi;
typedef vector<long long> vll;
#define ll long long
#define inf LLONG_MAX
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input a 2D array of characters. It should return true if the
// board is valid, else should return false.
bool isValidSudoku(vector<vector<char> > a) {
    // write your code here.
    unsigned int r[9], c[9], sm[3][3];
    fill(r);
    fill(c);
    fill(sm);

    for(int i = 0 ; i < 9; i++){
        for(int j = 0 ; j < 9; j++){
            if(a[i][j] != '.') {
                if((r[i]&(1<<(a[i][j]-'0'))) != 0)
                    return false;
                else
                    r[i] |= (1 << (a[i][j]-'0'));
                if((c[j]&(1<<(a[i][j]-'0'))) != 0)
                    return false;
                else c[j] |= (1 << (a[i][j]-'0'));
                if((sm[i / 3][j / 3] & (1<<(a[i][j]-'0'))) != 0)
                    return false;
                else sm[i / 3][j / 3] |= (1 << (a[i][j]-'0'));
            }
        }
    }
    return true;




}

int main(int argc, char** argv){
    vector<vector<char> > board(9, vector<char> (9));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin>>board[i][j];
        }
    }
    if (isValidSudoku(board)) {
        cout<<"Valid";
    } else {
        cout<<"Invalid";
    }

}