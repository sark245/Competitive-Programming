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

class AdaptedStack{
    queue<int>data;
    queue<int>helper;
public:
    AdaptedStack(){}
    void ASpush(int val){
        data.push(val); //Push in O(1)
    }

    void ASpop(){

        if(data.empty()){
            cout<<"Stack is Empty\n";
        }
        else {
            while (data.size() != 1) {
                helper.push(data.front());
                data.pop();
            }
            data.pop();
            while(!helper.empty()){
                data.push(helper.front());
                helper.pop();
            }
        }
    }
    int AStop(){
        if(data.empty()){
           return -1;
        }
        else {
            while (data.size() != 1) {
                helper.push(data.front());
                data.pop();
            }
            int ret = data.front();
            data.pop();
            helper.push(ret);
            while(!helper.empty()){
                data.push(helper.front());
                helper.pop();
            }
            return ret;
        }

    }



};

main() {
    IOS
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //Push Efficient

    AdaptedStack st;

    rep(i,10){
        st.ASpush(i);
    }

    rep(i,10){
        cout<<st.AStop()<<" ";
        st.ASpop();
    }
}