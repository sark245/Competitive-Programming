//Archit Aggarwal, NSIT
//architaggarwal0508@gmail.com
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void display(vector<vector<int>> dp) {
    for(int i = 0; i < dp.size(); i++) {
        for(int j = 0; j < dp[i].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
int maxsquare(vector<vector<int>> input) {
    vector<vector<int>> dp(input.size(), vector<int>(input[0].size(), 0));
    for (int j = 0; j < dp[dp.size()- 1].size(); j++) {
        dp[dp.size()- 1][j] = input[dp.size()- 1][j];
    }
    for (int i = 0; i < dp.size(); i++) {
        dp[i][dp[i].size() - 1] = input[i][dp[i].size()- 1];
    }
    int maximum = 0;
    for (int i = dp.size() - 2; i >= 0; i--) {
        for (int j = dp[i].size() - 2; j >= 0; j--) {
            if(input[i][j] == 0) continue;
            else {
                int f1, f2, f3;
                f1 = dp[i][j + 1];
                f2 = dp[i + 1][j + 1];
                f3 = dp[i + 1][j];
                dp[i][j] = 1 + min(f1, min(f2, f3));
                maximum = max(maximum, dp[i][j]);
            }
        }
    }
    //display(dp);
    return maximum;
}
int main() {
    vector<vector<int>> input = {
        {0,1,1,0,1,1,1},
        {1,1,1,0,1,1,0},
        {0,1,1,1,0,1,1},
        {1,1,1,1,1,1,1},
        {1,1,1,1,1,0,1},
        {0,1,1,1,1,1,0},
    };
    cout << maxsquare(input);
}