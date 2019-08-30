#include <bits/stdc++.h>
using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;
ll mod = (ll)1e9 + 7;
#define cases ll t;cin>>t;while(t--)
int amount[7];
int final_scores[7];


signed main(){



    for(int i = 0; i < 6 ; i++) {
        amount[i] = 600;
        final_scores[i] = 0;
    }


    for(int R = 1; R <= 6; R++) {
        cout<<endl;
        pair<int, int> bids[7];
        int score[7];

        for (int i = 0; i < 6; i++) {
            cout << "Enter Team " << i + 1 << " Bid = ";
            cin >> bids[i].first;
            bids[i].second = i;
        }


        sort(bids, bids + 6);
        memset(score, 0, sizeof score);

        int d_vals = 0;
        for (int i = 0; i < 6; i++) {
            if (bids[i].first != bids[i + 1].first)
                d_vals++;
        }
        if (d_vals == 1) {
            continue;
        } else if (d_vals == 2) {
            for(int i = 0; i < 6; i++){
                amount[bids[i].second] -= bids[i].first;
            }
            int highest = bids[5].first;
            int S_highest = bids[0].first;
            for(int i = 0; i < 6; i++){
                if(bids[i].first == S_highest){
                    score[bids[i].second] -= S_highest;
                } else
                    score[bids[i].second] += (100-highest);
            }

        } else if (d_vals == 3) {
            for(int i = 0; i < 6; i++){
                amount[bids[i].second] -= bids[i].first;
            }
            int highest = bids[5].first;
            int T_highest = bids[0].first;
            int S_highest = -1;
            for(int i = 0; i < 6; i++){
                if(bids[i].first != highest && bids[i].first != T_highest){
                    S_highest = bids[i].first;
                    break;
                }
            }

            for(int i = 0; i < 6; i++){

                amount[bids[i].second] -= bids[i].first;
                if(bids[i].first == T_highest){
                    score[bids[i].second] -= 30*R;
                }else if(bids[i].first == S_highest){
                    score[bids[i].second]-= S_highest;
                }else
                    score[bids[i].second] += (100-bids[5].first);
            }


        }else {

            for(int i = 0; i < 6; i++){
                amount[bids[i].second] -= bids[i].first;
            }

            int highest = bids[5].first;
            int lowest = bids[0].first;
            int S_lowest = -1;
            int S_highest = -1;
            for(int i = 0; i < 6; i++)
                if(bids[i].first != lowest){
                    S_lowest = bids[i].first;
                    break;
                }

        for(int i = 5; i >= 0; i--){
            if(bids[i].first != highest){
                S_highest = bids[i].first;
                break;
            }
        }

        for(int i = 0; i < 6; i++){
            if(bids[i].first == highest){
                score[bids[i].second] += (100 - highest);
            }else if(bids[i].first == S_highest){
                score[bids[i].second] -= S_highest;
            }else if(bids[i].first == S_lowest){
                score[bids[i].second] -= 15*R;
            }else if(bids[i].first == lowest){
                score[bids[i].second] -= 30*R;
            }
        }
        }

        cout<<"**********************************************************************\n\n";
        cout<<"Scores After Round "<<R<<"\n\n";

        for(int i = 0; i < 6; i++){
            cout<<"Score of Team "<<i+1<<" = "<<score[i]<<"\n";
            final_scores[i] += score[i];
        }


    }

    cout<<"**************************************************************************\n\n";
    cout<<"\t\tOVERALL FINAL SCORES\n\n";
    for(int i = 0; i < 6; i++)
        cout<<"TEAM "<<i+1<<" = "<<final_scores[i]<<"\n";







}