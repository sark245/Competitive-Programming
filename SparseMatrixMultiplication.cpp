//
// Created by sark2 on 19-06-2019.
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

vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
    //Write your code here
    vector<vector<int>> C;

    int x = 0;
    for(int i = 0; i<A.size(); ++i){
        vector<int>row;
        for(int j = 0; j < B[0].size(); ++j){
            for(int k = 0; k < B.size(); ++k){
                if(A[i][k]==0) continue;
                 x +=(A[i][k]*B[k][j]);
            }
            row.push_back(x);
            x = 0;
        }
        C.push_back(row);
    }
    return C;
}

int main(){
    IOS
    //Main Function
    int arow, acol;
    cin>>arow>>acol;
    vector<vector<int> > a(arow, vector<int> (acol));
    for(int i=0;i<arow;i++){
        for(int j=0;j<acol;j++){
            cin>>a[i][j];
        }
    }
    int brow, bcol;
    cin>>brow>>bcol;
    vector<vector<int> > b(brow, vector<int> (bcol));
    for(int i=0;i<brow;i++){
        for(int j=0;j<bcol;j++){
            cin>>b[i][j];
        }
    }
    vector<vector<int> > res(arow, vector<int> (bcol));
    res=multiply(a,b);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
