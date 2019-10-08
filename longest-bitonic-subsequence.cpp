//Archit Aggarwal, NSIT
//architaggarwal0508@gmail.com
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int lbsq(vector<int> v) {
    vector<int> dp1(v.size(), 1), dp2(v.size(), 1);
    for(int i = 1; i < dp1.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(v[j] < v[i]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    for(int i = dp2.size() - 2; i >= 0; i--) {
        for(int j = dp2.size() - 1; j > i; j--) {
            if(v[j] < v[i]) {
               dp2[i] = max(dp2[i], dp2[j] + 1); 
            }
        }
    }
    int globalmax = 1;
    for(int i = 0; i < v.size(); i++) {
        globalmax = max(globalmax, dp1[i] + dp2[i] - 1);
    }
    return globalmax;
}
int main(int argc, char const *argv[])
{
    vector<int> v = {10, 22, 9, 33, 21, 50, 41, 60, 80, 1};
    cout << lbsq(v) << endl;
    return 0;
}