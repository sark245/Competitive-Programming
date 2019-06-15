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
#define int long long
#define inf LLONG_MAX
//int mod=1e9+7;
int mini(int a,int b,int c){
    min(min(a,b),c);

}
main() {
    IOS
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

  string s;
    cin>>s;
    stack<char>st;
    repA(i,0,s.length()-1){
        if(s[i] == '{' || s[i] == '(' || s[i] =='[') st.push(s[i]);
        else if(s[i] == ')'){
            if(st.top() == '(') st.pop();
        }
        else if(s[i] == '}'){
            if(st.top() == '{') st.pop();
        }
        else if(s[i] == ']'){
            if(st.top() == '[') st.pop();
        }
    }

    cout<<((st.size()>0)?"not balanced":"balanced");

}


