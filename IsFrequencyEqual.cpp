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
bool isFreqEqual(string s){
    unordered_map<char,int>freq;
    unordered_map<int,int>f2;
    for(auto i : s) {
        freq[i]++;
    }
    for(auto i : freq){
        f2[i.second]++;
    }
    if(f2.size()>2) return false;
    else{
        int c = 0;
        for(auto i : f2){
            if(i.second > 1) c++;
        }
        if(c==1) return true;
        else return false;
    }



}

int main(){
    IOS
    string s;
    cin>>s;
    if(isFreqEqual(s)){
        cout<<"true";
    }
    else cout<<"false";
}