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

// ll pwr(ll a, ll b);
	

#define rep(i, a, n) for(int i = a; i < n; i++)

int mul(int a, int b){
	return (ll)a * b % mod;
}

struct Matrix{
	vector<vector<int>> mat;
	int n, m; 

	Matrix(int n, int m){
		this->n = n;
		this->m = m;
		mat.assign(n, vector<int>(m, 0));
	}

	Matrix operator*(const Matrix other){
		Matrix R(n, other.m);

		rep(i, 0, n){
			rep(j, 0, other.m){
				rep(k, 0, m){
					R.mat[i][j] += mul(mat[i][k] % mod, other.mat[k][j] % mod);
					R.mat[i][j] %= mod;
				}
			}
		}

		return R;
	}


};

Matrix pwr(Matrix a, ll n){
	Matrix res(a.n, a.m);

	rep(i, 0, a.n){
		res.mat[i][i] = 1;
	}

	while(n){
		if(n & 1){
			res = res * a;
		}
		a = a * a;
		n >>= 1;
	}
		
	return res;

}


int main(){
   IOS

   int n, m; ll k;
   cin>>n>>m>>k;

   Matrix A(n, n);

	rep(i, 0, m){
		int u, v; cin>>u>>v;
		u--, v--;
		A.mat[u][v] = 1;
	}

	Matrix res = pwr(A, k);

	ll sum = 0;
	rep(i,0, n){
		rep(j, 0, n){
			sum += res.mat[i][j];
			if(sum >= mod)sum -= mod;
		}
	}

	cout<<sum<<'\n';






}

	
