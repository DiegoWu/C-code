#include<bits/stdc++.h>

#define ll long long 
#define ld long double
#define maxn 10000000
#define mod 998244353
#define mp make_pair

using namespace std;

using P= pair<int, ll>; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(NULL); 
	int n, a; 
	cin>>n;
	ll ans= n; 
	vector<ll> v(n); 
	vector<vector<P> > dp(2); 

	for(int i=0; i<n; i++){
		cin>>a; 
		v[i]= a; 
		dp[0].push_back(mp(i, a));
	}
	int pvt= n; 

	for(int i=0; i<n-1; i++){
		int temp= 0; 
		for(int j=0; j<pvt; j++){
			for(int k=dp[i%2][j].first+1; k<n; k++){

				if(k==n-1) {if((dp[i%2][j].second+v[k])%(i+2)==0) ans++;} 

				else{
					dp[(i+1)%2].push_back(mp(k, dp[i%2][j].second+v[k]));  
					
					if((dp[i%2][j].second+v[k])%(i+2)== 0) ans++; 
					
					temp++; 
				}

				ans%= mod;
			}

			dp[i%2].clear(); 
		}
		pvt= temp;
	}
	cout<<ans%mod<<endl;
}
