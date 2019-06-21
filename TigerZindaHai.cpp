//
// Created by sark2 on 21-06-2019.
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
int open_close(vector<string> T){
    int n = T.size();
    unordered_set<int>set;
    trav(i,T){
        if(i != "END") {
            int num = stoi(i);
            if (set.find(num)==set.end())
                set.insert(num);
            else set.erase(num);
        }
        else set.clear();

    }
    return set.size();
}

int main(){
    IOS

    int n;
    cin>>n;
    vector<string> T;
    for(int i = 0; i< n; i++){
        string s;
        cin>>s;
        T.push_back(s);
    }
    cout<<open_close(T);
}