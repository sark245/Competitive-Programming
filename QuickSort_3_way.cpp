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
    

void partition(int a[], int low, int high, int &i, int &j){
    if(high - low <= 1){
        if(a[high] < a[low])swap(a[high], a[low]);
        i = low;
        j = high;
        return;
    }

    int mid = low;
    int pivot = a[high];
    while(mid <= high){
        if(a[mid] < pivot)swap(a[low++], a[mid++]);
        else if(a[mid] == pivot)mid++;
        else if(a[mid] > pivot)swap(a[mid], a[high--]);
    }
    i = low - 1;
    j = mid;
}

void QuickSort_3_way(int a[], int low, int high){
    if(low >= high)return;
    int i, j; 
    partition(a, low, high, i, j);
    QuickSort_3_way(a, low, i);
    QuickSort_3_way(a, j, high);
}

int main(){
   IOS

    //int a[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4}; 
    int a[] = {4, 39, 54, 14, 31, 89, 44, 34, 59, 64, 64, 11, 41}; 
    //int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    //int a[] = {91, 82, 73, 64, 55, 46, 37, 28, 19, 10}; 
    //int a[] = {4, 9, 4, 4, 9, 1, 1, 1}; 
    int size = sizeof(a) / sizeof(int); 
    
    for(int i = 0; i < size; i++){
        cout<<a[i]<<" ";
    }cout<<'\n';
    
    QuickSort_3_way(a, 0, size - 1); 

    for(int i = 0; i < size; i++){
        cout<<a[i]<<" ";
    }cout<<'\n';
     
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

