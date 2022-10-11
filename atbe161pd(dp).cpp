#include<bits/stdc++.h>

#define ll long long 
#define maxn 3003
#define mod 1000000007
#define mp make_pair

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; 
	cin>>n>>m; 
	ll dp[n+1][n+1];
	ll v[n+1], a[n+1]; 
	
 	for(int i=1; i<n+1; i++) cin>>v[i]; 
	memset(a, 0, sizeof(a)); 
	memset(dp, 0, sizeof(dp)); 
	for(int i=0; i<m; i++){
		int c, d; 
		cin>>c>>d; 
		a[c]= d; 
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			dp[i][j]= dp[i-1][j-1]+v[i]+a[j]; 
		}	
		for(int j=0; j<i; j++) dp[i][0]= max(dp[i][0], dp[i-1][j]); 
	}	
	ll ans= 0; 
	for(int i=0; i<=n; i++) ans= max(dp[n][i], ans); 
	cout<<ans<<endl;
	
}
