//
// Created by sark2 on 19-12-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define pb push_back
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define CASES int t;cin>>t;while(t--)

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int n;
const int nmax = 1e5+10;

int a[nmax];
unordered_set<int>h2;

int main() {

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        h2.insert(a[i]);
    }
    if(h2.size() == 1 && n != 1){
        cout<<1<<"\n";
        cout<<*h2.begin();
    }else{
    sort(a, a+n);

    if(n == 1){
        cout<<-1;
        return 0;
    }else if(n == 2){
        if((a[1]-a[0]) % 2 == 0 && (a[1] - a[0]) != 0){
            cout<<3<<"\n";
            ll d = a[1] - a[0];
            vector<int>ans;
            ans.pb(a[0]-d);
            ans.pb(a[1]+d);
            ans.pb(a[0]+d/2);
            sort(ans.begin(), ans.end());
            for(auto i : ans){
                cout<<i<<" ";
            }
        }else{
            cout<<2<<"\n";
            ll d = a[1] - a[0];
            cout<<min(a[0]-d, a[1]+d)<<" "<<max(a[0]-d, a[1]+d);
        }
    }else {
        vector<ll> helper;
        set<ll> st;
        for (int i = 0; i < n - 1; i++) {
            helper.pb(a[i + 1] - a[i]);
            st.insert(a[i + 1] - a[i]);
        }

        if (st.size() == 1) {
            cout << 2 << "\n";
            ll d = helper[0];
            cout << min(a[0] - d, a[n - 1] + d) << " " << max(a[0] - d, a[n - 1] + d);
        } else if (st.size() == 2) {
            vector<ll> b;
            b = helper;
            sort(b.begin(), b.end());
            /*for(auto i : b)cout<<i<<" ";
            cout<<endl;*/
            if (n == 3 || (b[n - 2] != b[n - 3] && b[0] == b[1])) {

                int idx = 0;
                ll mx = helper[0];

                for (int i = 1; i < n - 1; i++) {
                    if (mx < helper[i]) {
                        mx = helper[i];
                        idx = i;
                    }
                }
                if(mx % 2 == 0 && mx == 2*(*st.begin())) {
                    cout << 1 << "\n";
                    cout << a[idx] + mx / 2;
                }else{
                    cout<<0;
                }
            } else {
                cout << 0;
            }

        } else {
            cout << 0;
        }
    }


    }



}
