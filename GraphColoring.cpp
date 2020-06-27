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
    
#define V 4

void printSol(int color[]);

bool isSafe(int v, 
        bool g[V][V], int color[], int c){
            
            for(int i = 0; i < V; i++){
                if(g[v][i] && c == color[i])
                return false;
            }
            return true;
}

bool helper(bool g[V][V], int m, int color[], int v){
    if(v == V)return true;

    for(int c =1 ; c <= m; c++){
        if(isSafe(v, g, color, c)){
            color[v] = c;
            if(helper(g, m, color, v + 1))return true;

            color[v] = 0;
        }
    }
    return false;
}

bool graphColor(bool g[V][V], int m){
    int color[V];
    for(int i = 0; i < V; i++)
        color[i] = 0;
    
    if(helper(g, m, color, 0) == false){
        cout<<"No Solution\n";
        return false;
    }
    printSol(color);
    return true;
}

void printSol(int color[]){
    for(int i = 0; i < V; i++){
        cout<<color[i]<<" ";
    }
    cout<<"\n";
}


int main(){
   IOS

   bool graph[V][V] = { 
        { 0, 1, 1, 1 }, 
        { 1, 0, 1, 0 }, 
        { 1, 1, 0, 1 }, 
        { 1, 0, 1, 0 }, 
    }; 
    int m = 3; // Number of colors 
    graphColor(graph, m); 
    return 0; 

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

