#include<iostream>
#include<vector> 
#define ll long long 
#define mod 998244353
using namespace std; 

int main(){

	int n, m, k; 
	cin>>n>>m>>k; 
	vector<vector<ll> >dp(n+1, vector<ll>(k+1)); 
	dp[0][0]= 1; 
	for(int i=1; i<n+1; i++){
		for(int j=0; j<k; j++){
			for(int x=1; x<m+1; x++){
				if(x+j<= k) dp[i][x+j]+= dp[i-1][j]%mod; 
			}
		}
	}
	ll ans= 0; 
	for(int i=1; i<k+1; i++){
		ans+= dp[n][i]; 
		ans%= mod;
	}
	cout<<ans<<endl;
}