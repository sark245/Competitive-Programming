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
    
const int N = 1000000;

int partition(int arr[], int lo, int hi){
    int pivot = arr[hi];
    int i = lo - 1;

    for(int j = lo; j < hi; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[hi]);
    return i + 1;
}

void QuickSort(int arr[], int lo, int hi){
    if(lo < hi){
        int j = partition(arr, lo, hi);
        QuickSort(arr, lo, j - 1);
        QuickSort(arr, j + 1, hi);
    }
}


int main(){
   IOS

   int arr[N], dupArr[N];

   
   clock_t begin, end;
   double time_spent;

   for(int i = 0; i < N; i++){
       dupArr[i] = arr[i] = rand() % 100000;
   }

   begin = clock();
   QuickSort(arr, 0, N);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout<<"Time taken by QuickSort - "<<time_spent<<"\n";

    time_spent = 0.0;
    begin = clock();
    sort(dupArr, dupArr + N);
    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout<<"Time Spent by C++ sort() - "<<time_spent<<"\n";

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

