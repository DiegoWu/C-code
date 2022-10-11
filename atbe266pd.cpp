#include<bits/stdc++.h> 
#define ll long long 
#define maxn 10000
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	
	int n;
	cin>>n; 
	ll dp[maxn+1][5]; 
	memset(dp, 0, sizeof(dp)); 
	vector<int> t(n), x(n), val(n); 
	for(int i=0; i<n; i++){

		cin>>t[i]>>x[i]>>val[i]; 
		dp[t[i]][x[i]]= val[i]; 
	}

	ll ans= 0; 
	for(int i=0; i<n; i++){
		ll temp= 0; 
		for(int j=0; j<5; j++){
			int pos= abs(x[i]-j); 
			if(t[i]-pos<= 0) continue; 
			if(t[i]-pos== t[i]&& j== x[i]) continue; 
			temp= max(temp, dp[t[i]-pos][j]);  
			
		}
		dp[t[i]][x[i]]+= temp; 
		cout<<dp[t[i]][x[i]]<<endl;
		if(t[i]< x[i]) continue; 
		ans= max(dp[t[i]][x[i]], ans); 
	}
	cout<<ans<<endl;
}
