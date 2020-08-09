//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);
    




int main(){
   IOS

    
    unordered_map<char, int>value;
    
    string h = "^/*+-";
    int h2[] = {3, 2, 2, 1, 1};
    for(int i = 0 ; i < 5; i++){
        value[h[i]] = h2[i];
    }


    
    
    int t; cin>>t;

    while(t--){
        string s;
        cin>>s;

        stack<char> st;
        st.push('N');

        int n = sz(s);
        string ans;

        for(int i = 0; i < n; i++){
            if(isalpha(s[i])){
                ans += s[i];
            }else if(s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                while(st.top() != 'N' && st.top() != '('){
                    ans += st.top();
                    st.pop();0
                }
                if(st.top() == '('){
                    st.pop();
                }
            }else{
                while(st.top() != 'N' && value[s[i]] <= value[st.top()]){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(st.top() != 'N'){
            ans += st.top();
            st.pop();
        }
        cout<<ans<<'\n';

    }




}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1) res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

